#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
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
const auto INF = numeric_limits<T>::max() / 2;

vector<int> color;
int LIS(vector<ll> &A){
  int n = A.size();
  color.resize(n);
  vector<ll> dp;
  rep(i, n){
    if(dp.empty()){
      color[i] = 0;
      dp.eb(A[i]);
    }else{
      int it = lower_bound(ALL(dp), A[i]) - dp.begin();
      if(it >= dp.size()){
        color[i] = dp.size();
        dp.pb(A[i]);
      }else{
        color[i] = it;
        dp[it] = A[i];
      }
    }
  }
  return (int)dp.size();
}



void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<ll> A(n);
  rep(i, n){
    ll d = s[i] - 'a';
    A[i] = 50 - d;
  }
  cout << LIS(A) << endl;
  rep(i, n){
    cout << color[i] + 1 << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}