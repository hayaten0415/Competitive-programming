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

int dp[100010][20];

int main() {
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<P> E[N+1];
  vector<int> A(M), B(M), S(M), T(M);
  rep(i, M){
    cin >> A[i] >> B[i] >> S[i] >> T[i];
    A[i]--, B[i]--;
    E[A[i]].pb({S[i], i});
  }
  rep(i, N) sort(ALL(E[i]));
  auto nextIndex = [&](int pos, int nowtime)-> int {
    auto res = lower_bound(ALL(E[pos]), make_pair(nowtime, -1));
    if (res == E[pos].end()) return M;
    return res->second;
  };
  auto getAns = [&](int X, int Y, int Z)-> P {
    int next = nextIndex(Y, X);
    if(next == M)return {Y, -1};
    if (Z <= S[next]) return { Y, -1 };
    else if (S[next] < Z && Z <= T[next]) return { A[next], B[next] };
    int curtime = T[next];
    int curedge = next;
    rrep(p, 20) {
      int nxt = dp[curedge][p];
      if (nxt == M) continue;
      if (T[nxt] < Z) {
          curtime = T[nxt];
          curedge = nxt;
      }
    }
    next = nextIndex(B[curedge], curtime);
    if (next == M) return { B[curedge], -1 };
    if (Z <= S[next]) return { A[next], -1 };
    if (S[next] < Z && Z <= T[next]) return { A[next], B[next] };
    return { B[next], -1 };
  };
  rep(i, M) dp[i][0] = nextIndex(B[i], T[i]);
  rep(i, 20) dp[M][i] = M;
  rep(p, 1, 20) rep(edge, 0, M) dp[edge][p] = dp[dp[edge][p - 1]][p - 1];
  while(Q--){
    int X, Y, Z;
    cin >> X >> Y >> Z;
    Y--;
    auto ans = getAns(X, Y, Z);
    cout << ans.first + 1;
    if(0<= ans.second)cout << " " << ans.second + 1;
    cout << endl;
  }
}