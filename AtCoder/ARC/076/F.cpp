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


using S = int;
using F = int;
S op(S a, S b) { return std::min(a, b); }
S e() { return INF<int>; }
S mapping(F f, S x) {
  return f + x;
}
F composition(F f, F g) { 
  return f + g;
}
F id() { return 0; }

bool lessR(const P& pleft, const P& pright){
    if (pleft.second == pright.second) return pleft.first < pright.first;
    else return pleft.second < pright.second;
}


int main() {
  int N, M;
  cin >> N >> M;
  vector<P> range(N);
  vector<bool> isUsed(N, false);
  rep(i, N) {
    cin >> range[i].se >> range[i].fi;
  }
  sort(range.begin(), range.end(), lessR);
  int numUsed = 0;
  vector<int> tmp1(M+1);
  for (int i=1; i<=M; i++) tmp1[i] = i;
  lazy_segtree<int, op, e, int, mapping, composition, id> seg(tmp1);
  rep(i, N){
    int q = min(M + 1 - range[i].fi, M);
    if(seg.prod(q, M +1) > 0){
      seg.apply(q, M+1, -1);
      isUsed[i] = true;
      numUsed++;
    }
  }
  int Mnew = M - numUsed;
  vector<int> tmp2(Mnew+1);
  for (int i=1; i<=Mnew; i++) tmp2[i] = i;
  lazy_segtree<int, op, e, int, mapping, composition, id> seg2(tmp2);
  rep(i, N){
    if (isUsed[i]) continue;
    int q = min(range[i].second, Mnew);
    if(seg2.prod(q, Mnew +1) > 0){
      seg2.apply(q, Mnew + 1, -1);
      numUsed++;
    }
  }
  cout << N - numUsed << endl;
}