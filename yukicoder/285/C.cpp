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
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
#define sz(x) ((ll)(x).size())
using namespace atcoder;
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
const auto INF = numeric_limits<T>::max()/2;
using mint = modint1000000007;
int main() {
  string s;
  cin >> s;
  int n = s.size();
  // [i桁目][5の出現回数][2で割れる数の出現回数(0以外)][0が出現したかどうか][less][non-leadingzero];
  mint dp[n + 1][3][3][2][2][2] = {0};
  dp[0][0][0][0][0][0] = 1;
  rep(i, n)rep(j, 3)rep(e, 3)rep(f, 2)rep(k, 2)rep(l, 2){
    ll nd = s[i] - '0';
    rep(d, 10){
      ll nj = j;
      ll ne = e;
      ll nf = f;
      ll nk = k;
      ll nl = l;
      if(d == 2 || d == 6)ne++;
      if(d == 4)ne += 2;
      if(d == 8)ne += 3;
      if(d == 5)nj++;
      if(ne > 2)ne = 2;
      if(nj > 2)nj = 2;
      if(d < nd)nk = 1;
      if(nk == 0 && d > nd)continue;
      if(d == 0 && l == 1)nf = 1;
      if(!(d == 0))nl = 1;
      dp[i+1][nj][ne][nf][nk][nl] += dp[i][j][e][f][k][l];
    }
  }
  mint ans = dp[n][2][2][0][0][1] + dp[n][2][2][0][1][1];
  cout << ans.val() << endl; 
}