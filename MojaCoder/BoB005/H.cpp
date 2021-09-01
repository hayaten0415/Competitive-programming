#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;
ll ans = 0;
int main() {
  vector<string> grid(3);
  rep(i, 3) cin >> grid[i];
  auto dfs = [&](auto &&self, vector<string> s){
    rep(i, 3){
      int cn1 = 0;
      int cn2 = 0;
      rep(j, 3){
        if(s[i][j] == 'o')cn1++;
        if(s[j][i] == 'o')cn2++;
      }
      if(cn1 == 3){
        ans++;
        return;
      }
      if(cn2 == 3){
        ans++;
        return;
      }
    }
    if(s[0][0] == s[1][1] && s[1][1] == s[2][2] && s[0][0] == 'o'){
      ans++;
      return;
    }
    if(s[0][2] == s[1][1] && s[1][1] == s[2][0] && s[1][1] == 'o'){
      ans++;
      return;
    }
    rep(i, 3)rep(j, 3){
      if(s[i][j] == 'o')continue;
      s[i][j] = 'o';
      self(self, s);
      s[i][j] = '.';
    }
    return;
  };
  vector<string> t = grid;
  rep(i, 3)rep(j, 3){
    if(grid[i][j] == 'o')continue;
    t[i][j] = 'o';
    dfs(dfs, t);
    t[i][j] = '.';
  }
  cout << ans << endl;
}