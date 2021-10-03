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


vector<int> G[1010];
int N, M, used[1010];

void dfs(int cur, vector<int> &dist) {
    for(auto to : G[cur]) {
        if(dist[to] >= 0) continue;
        dist[to] = dist[cur] + 1;
        dfs(to, dist);
    }
}

pair<int, int> get_graph_info(int id) {
    vector<int> d0(N, -1), d1(N, -1), d2(N, -1);
    d0[id] = 0; dfs(id, d0);

    // 直径は p1 と p2 をつなぐパスになる
    int p1 = max_element(d0.begin(), d0.end()) - d0.begin();
    d1[p1] = 0; dfs(p1, d1); // d1 は p1 からの距離を記憶したもの
    int p2 = max_element(d1.begin(), d1.end()) - d1.begin();
    d2[p2] = 0; dfs(p2, d2); // d2 は p2 からの距離を記憶したもの
    int diam = d2[p1];

    int mi = INF<int>, res = -1;
    for(int i=0; i<N; i++) {
        if(d1[i] < 0 or d2[i] < 0) continue;
        used[i] = true;
        int tmp = max(d1[i], d2[i]);
        if(mi > tmp) mi = tmp, res = i;
    }
    return make_pair(diam, res);
}




void solve() {
  cin >> N >> M;
  for(int i=0; i<M; i++) {
      int u, v;
      cin >> u >> v;
      u--; v--;
      G[u].push_back(v);
      G[v].push_back(u);
  }
  // (直径, 中心となる頂点)
  vector< pair<int, int> > cand;
  for(int i=0; i<N; i++) {
      if(used[i]) continue;
      pair<int, int> info = get_graph_info(i);
      cand.push_back(info);
  }
  sort(cand.rbegin(), cand.rend());
  vector< pair<int, int> > edges;
  for(int i=1; i<cand.size(); i++) {
      int u = cand[0].second, v = cand[i].second;
      edges.emplace_back(u+1, v+1);
      G[u].push_back(v);
      G[v].push_back(u);
  }
  pair<int, int> whole = get_graph_info(0);
  cout << whole.fi << endl;
  for(auto e : edges) {
    cout << e.first << " " << e.second << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}