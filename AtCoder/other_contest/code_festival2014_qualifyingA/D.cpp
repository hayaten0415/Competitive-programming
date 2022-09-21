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


ll dp[20][1LL<<10][3];
signed main(void)
{
  ll A;
  ll K;
  cin >> A >> K;
  string a = to_string(A);
  ll n = a.size();

  memset(dp, -1, sizeof(dp));
  dp[0][0][0] = 0;
  REP(i, n) {
    REP(j, 1<<10) REP(k, 3) {
      if(dp[i][j][k] == -1) continue;
      REP(d, 10) {
        ll tmp = j;
        if(!(j & (1<<d))) tmp |= 1<<d;
        // tmpで桁が1の中からどれを選ぶのが最善か？
        if(k == 0) {
          if(tmp & 1<<(a[i]-'0')) dp[i+1][tmp][0] = dp[i][j][k]*10 + a[i]-'0';
          REP(l, a[i]-'0') if(tmp & 1<<l) {
            chmax(dp[i+1][tmp][1], dp[i][j][k]*10 + l);
          }
          for(ll l=9; l>a[i]-'0'; --l) if(tmp & 1<<l) {
            if(dp[i+1][tmp][2] == -1) dp[i+1][tmp][2] = dp[i][j][k]*10 + l;
            chmin(dp[i+1][tmp][2], dp[i][j][k]*10 + l);
          }
        }
        // 小さいのが確定
        else if(k == 1) {
          REP(l, 10) if(tmp & 1<<l) {
            chmax(dp[i+1][tmp][1], dp[i][j][k]*10 + l);
          }
        }
        // 大きいのが確定
        else if(k == 2) {
          for(ll l=9; l>=0; --l) {
            if(tmp & 1<<l) {
              if(dp[i+1][tmp][2] == -1) dp[i+1][tmp][2] = dp[i][j][k]*10 + l;
              chmin(dp[i+1][tmp][2], dp[i][j][k] * 10 + l);
            }
          }
        }
      }
    }
  }

  ll ans = INF<ll>;
  REP(i, 1<<10) REP(k, 3) {
    ll cnt = 0;
    REP(j, 10) if(i & (1<<j)) cnt++;
    if(cnt <= K) {
      if(dp[n][i][k] != -1 && abs(ans-A) > abs(dp[n][i][k]-A)) {
        ans = dp[n][i][k];
      }
    }
  }
  ll r = 0;
  REP(i, n-1) r *= 10, r += 9;
  cout << min(abs(A-ans), abs(A-r)) << endl;
}