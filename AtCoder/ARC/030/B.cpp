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

int main() {
  int n, x;
  cin >> n >> x;
  x--;
  Graph G(n);
  vector<int> treasure(n);
  vector<int> pre(n, -1), dist(n, INF);
  vector<bool> visited(n, false);
  visited[x] = true;
  rep(i, n) cin >> treasure[i];
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  queue<int> que;
  que.push(x);
  dist[x] = 0;
  while (!que.empty()){
    int u = que.front();
    que.pop();
    for (auto v : G[u]){
      if(dist[v]!= INF)continue;
      dist[v] = dist[u] + 1;
      pre[v] = u;
      que.push(v);
    }
  }
  int ans = 0;
  rep(i, n){
    if(treasure[i] == 0)continue;
    int now = i;
    while (true){
      if(visited[now])break;
      visited[now] = true;
      ans += 2;
      now = pre[now];
    }
  }
  cout << ans << endl;
}