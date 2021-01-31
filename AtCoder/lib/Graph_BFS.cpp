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

void bfs(int s, int n){
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
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  bfs(0, n);
}