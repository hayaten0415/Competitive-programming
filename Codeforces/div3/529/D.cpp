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


void solve() {
  int n;
  cin >> n;
  Graph G(n);
  vector<P> edge(n);
  int start = 0;
  int goal = -1;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[i] = {a, b};
    G[a].pb(b);
    G[b].pb(a);
    if(a == 0){
      if(b != edge[0].fi && b != edge[0].se)goal = b;
    }
    if(b == 0){
      if(a != edge[0].fi && a != edge[0].se)goal = a;
    }
  }
  if(n == 3){
    vector<int> A(n);
    rep(i, n) A[i] = i;
    cout << 1 << " " << 2 << " " << 3 << endl;
    return;
    do{
      vector<int> ind(n);
      rep(i, n) ind[A[i]] = i;
      bool ok = true;
      rep(i, n){
        if(ind[i] > ind[edge[i].fi])ok = false;
        if(ind[i] > ind[edge[i].se])ok = false;
      }
      if(ok){
        rep(i, 3){
          cout << A[i] + 1 << " ";
        }
        cout << endl;
        return;
      }
    } while (next_permutation(ALL(A)));
  }
  int pre = goal;
  rep(i, n-1){
    cout << start + 1 << " ";
    int tmp = -1;
    for(int v : G[start]){
      if(v == pre)continue;
      tmp = v;
    }
    pre = start;
    start = tmp;
  }
  cout << goal + 1 << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}