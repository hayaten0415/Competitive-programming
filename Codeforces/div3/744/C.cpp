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
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(int i=0;i<n;++i)
#define rep2(i,n) for(int i=0;i<n;++i)
#define rep3(i,a,b) for(int i=a;i<b;++i)
#define rep4(i,a,b,c) for(int i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define sz(x) ((ll)(x).size())
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline void Yes(bool b = true) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YES(bool b = true) { cout << (b ? "YES" : "NO") << '\n'; }
inline void OKNG(bool b = true) { cout << (b ? "OK" : "NG") << '\n'; }
const int dx[2] = {-1, -1};
const int dy[2] = {-1, 1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;


void solve() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  vector<vector<int>> dp(h, vector<int>(w, 20));
  vector<vector<int>> ok(h, vector<int>(w,0));
  auto dfs1 = [&](int x, int y)-> int{
    int res = 0;
    while(true){
      int p = res + 1;
      if(x < p || y < p || y + p >= w)break;
      if(s[x -p][y- p] == '.')break;
      if(s[x -p][y+ p] == '.')break;
      res = p;
    }
    return res;
  };
  auto dfs3 = [&](auto &&self, int x, int y, int d)-> void {
    rep(c, d+1){
      ok[x - c][y - c] = 1;
      ok[x - c][y + c] = 1;
    }
  };
  int cn = 0;
  rep(i, h)rep(j, w){
    if(s[i][j] == '.')continue;
    dp[i][j] = dfs1(i, j);
  }
  rep(i, h)rep(j, w){
    if(dp[i][j] >= k && s[i][j] == '*'){
      dfs3(dfs3, i, j, dp[i][j]);
    }
  }
  bool ok2 = true;
  rep(i, h)rep(j, w){
    if(s[i][j] == '.')continue;
    if(ok[i][j] == 0)ok2 = false;
  }
  YES(ok2);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}