#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = (1 << 30);
Graph G;

vector<int> bfs(int s, int n){
  vector<int> dist(n, INF);
  vector<int> pre(n, -1);
  dist[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for(int u: G[v]){
      if(dist[u] != INF) continue;
      dist[u] = dist[v] + 1;
      pre[u] = v;
      que.push(u);
    }
  }
  return dist;
}

int main() {
  int n, u, v;
  cin >> n >> u >> v;
  u--, v--;
  G.resize(n);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<int> dist1 = bfs(u, n);
  vector<int> dist2 = bfs(v, n);
  int ans = 0;
  rep(i, n){
    if(dist1[i] < dist2[i]){
      chmax(ans, dist2[i]);
    }
  }
  cout << ans - 1 << endl;
}