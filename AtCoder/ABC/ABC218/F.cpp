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
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
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
const auto INF = numeric_limits<T>::max()/2;

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n, vector<int>(n, -1));
  vector<P> edge(m);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[i] = {a, b};
    G[a][b] = i;
  }
  vector<P> memo(n);
  auto bfs = [&](int x) -> vector<int>{
    vector<int> dist(n, -1);
    dist[x] = 0;
    queue<int> que;
    que.push(x);
    while(!que.empty()){
      int v = que.front();
      que.pop();
      for(int j = 0; j < n; j++) if(dist[j] == -1 && G[v][j] != -1){
        dist[j] = dist[v] + 1;
        memo[j] = make_pair(v, G[v][j]);
        que.push(j);
      }
    }
    return dist;
  };
  vector<int> dis = bfs(0);
  vector<int> shortest_path;
  int now = n - 1;
  while(now != 0){
    shortest_path.pb(memo[now].se);
    now = memo[now].fi;
  }
  vector<int> ans(m, dis[n - 1]);
  for(int e : shortest_path){
    G[edge[e].first][edge[e].second] = -1;
    ans[e] = bfs(0)[n - 1];
    G[edge[e].first][edge[e].second] = e;
  }
  for(int x:ans)cout << x << endl;
  
}