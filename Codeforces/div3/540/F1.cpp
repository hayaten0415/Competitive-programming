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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;
Graph G;

int dep[300002];
int tree_size_red[300002];
int tree_size_blue[300002];
int A[300002];

void dfs(int v,int p, int d) {
  dep[v] = d;
  if(A[v] == 1)tree_size_red[v]++;
  if(A[v] == 2)tree_size_blue[v]++;
  for (int u : G[v]){
    if(u ==p)continue;
    dfs(u, v, d + 1);
    tree_size_red[v] += tree_size_red[u];
    tree_size_blue[v] += tree_size_blue[u];
  }
}



void solve() {
  int n;
  cin >> n;
  G.resize(n);
  rep(i, n) cin >> A[i];
  vector<P> edge(n - 1);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
    edge[i] = {a, b};
  }
  dfs(0, -1, 0);
  int ans = 0;
  for(auto [a, b] :edge){
    if(dep[b] < dep[a]){
      swap(a, b);
    }
    tree_size_blue[0] -= tree_size_blue[b];
    tree_size_red[0] -= tree_size_red[b];
    bool ok = true;
    if(tree_size_red[0] > 0 && tree_size_blue[0]> 0)ok = false;
    if(tree_size_red[b] > 0 && tree_size_blue[b] > 0)ok = false;
    tree_size_blue[0] += tree_size_blue[b];
    tree_size_red[0] += tree_size_red[b];
    if(ok)ans++;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}