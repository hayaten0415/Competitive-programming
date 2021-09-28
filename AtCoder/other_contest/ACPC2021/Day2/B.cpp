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
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;

constexpr int MAX = 3010, offset = 3010;
bool exist[MAX][MAX + offset];
P dp[MAX][MAX + offset];

void solve() {
  int n;
  cin >> n;
  dp[0][offset] = {0, 0};
  rep(i, n){
    int t, p;
    cin >> t >> p;
    if (abs(p) < MAX) exist[t][p + offset] = true;
  }
  rep(i, MAX)rep(j, MAX + offset) dp[i][j] = {-1, -1};
  dp[0][offset] = {0, 0};
  rep(i, MAX - 1) {
    rep(j, MAX + offset) if (dp[i][j].fi >= 0) {
      auto [num, sleep] = dp[i][j];
      if (j - 1 >= 0)chmax(dp[i + 1][j - 1], {num + exist[i + 1][j - 1], sleep});
      chmax(dp[i + 1][j], {num + exist[i + 1][j], sleep + (j == offset)});
      if (j + 1 < MAX + offset)chmax(dp[i + 1][j + 1], {num + exist[i + 1][j + 1], sleep});
    }
  }

  P ans = {0, 0};
  rep(i, MAX) rep(j, MAX + offset) if (exist[i][j]) chmax(ans, dp[i][j]);
  cout << ans.fi << " " << ans.se << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}