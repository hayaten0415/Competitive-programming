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
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> H(n);
  vector<int> hinan(k);
  vector<int> dist(n, -1);
  queue<int> que;
  rep(i, n) cin >> H[i];
  rep(i, k){
    cin >> hinan[i];
    hinan[i]--;
    dist[hinan[i]] = 0;
    que.push(hinan[i]);
  }
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    if(H[a] < H[b]){
      G[a].emplace_back(b);
    }else{
      G[b].emplace_back(a);
    }
  }
  while (!que.empty()){
    int u = que.front();
    que.pop();
    for(auto v : G[u]){
      if(dist[v] != -1)continue;
      dist[v] = dist[u] + 1;
      que.push(v);
    }
  }
  rep(i, n){
    cout << dist[i] << endl;
  }
}