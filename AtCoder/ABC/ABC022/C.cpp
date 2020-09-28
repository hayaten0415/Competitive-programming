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
const ll INF = (1LL << 40);
vector<vector<ll>> dist(310, vector<ll>(310,INF));

void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }  
}


int main() {
  int n, m;
  cin >> n >>  m;
  Graph G(n);
  vector<P> adj_dist;
  rep(i, n){
    dist[i][i] = 0;
  }
  rep(i, m){
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if(a != 0 && b != 0){
      dist[a][b] = c;
      dist[b][a] = c;
      continue;
    }
    if(a == 0){
      adj_dist.push_back({b, c});
    }else{
      adj_dist.push_back({a, c});
    }
  }
  warshall_floyd(n);
  ll ans = INF;
  for (auto i : adj_dist){
    for (auto j : adj_dist){
      if(i.first == j.first)continue;
      ans = min(ans, dist[i.first][j.first] + i.second + j.second);
    }
  }
  if(ans == INF){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}