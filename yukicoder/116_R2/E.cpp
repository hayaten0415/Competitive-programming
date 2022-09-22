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



long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}


mint solve(string &s){
  int n = s.size();
  // [i桁目][3で割ったあまり][8で割ったあまり][3が桁に含まれるか][n以下が確定したか]
  mint dp[n+1][3][8][2][2] = {0};
  dp[0][0][0][0][0] = 1;
  rep(a, n)rep(b, 3)rep(c, 8)rep(d, 2)rep(k, 2){
    int nf = s[a] - '0';
    rep(f, 10){
      ll nk = k;
      ll nd = d;
      if(f == 3)nd = 1;
      if(k == 0){
        if(f < nf)nk = 1;
        if(f > nf)continue;
      }
      ll nc = modpow(10, n -a-1, 8) * f + c;
      nc %= 8;
      ll nb = (f + b) % 3;
      dp[a + 1][nb][nc][nd][nk] += dp[a][b][c][d][k];
    }
  }
  mint ans = 0;
  // 3が含まれる数で8の倍数でないものの数え上げ
  rep(i, 7)rep(j, 3)ans += (dp[n][j][i+1][1][0] + dp[n][j][i+1][1][1]);
  // 3の倍数かつ8の倍数でないもの数え上げ
  rep(i, 7)rep(k, 2)ans += (dp[n][0][i+1][k][0] + dp[n][0][i+1][k][1]);
  // 3の倍数かつ桁に3が含まれるものかつ8の倍数でないものを引く
  rep(i, 7)ans -= (dp[n][0][i+1][1][0] + dp[n][0][i+1][1][1]);
  return ans;
}

bool A_ok(string &s){
  int n = s.size();
  bool three = false;
  bool eight = false;
  ll sum = 0;
  rep(i, n){
    ll d = s[i] - '0';
    sum += modpow(10, n -i-1, 8) * d;
    sum %= 8;
  }
  eight = (sum == 0);
  sum = 0;
  rep(i, n){
    ll d = s[i] - '0';
    if(d == 3)three = true;
    sum += d;
    sum %= 3;
  }
  if(!three)three = (sum == 0);
  return (three && !eight);
}

int main() {
  string A, B;
  cin >> A >> B;
  mint ans = solve(B) - solve(A);
  if(A_ok(A))ans += 1;
  cout << ans.val() << endl;
}