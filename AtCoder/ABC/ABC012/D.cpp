#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
typedef vector<vector<int>> Matrix;
Matrix dist;
const int INF = 100000000;

void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int main() {
  int n, m;
  cin >> n >> m;
  dist = Matrix(n, vector<int>(n, INF));
  rep(i, n) dist[i][i] = 0;
  rep(i, m){
    int a, b, t;
    cin >> a >> b >> t;
    a--, b--;
    dist[a][b] = t;
    dist[b][a] = t;
  }
  warshall_floyd(n);
  int ans = 1000000000;
  rep(i, n){
    int mx = 0;
    rep(j,n){
      if(i == j)continue;
      mx = max(mx, dist[i][j]);
    }
    ans = min(ans, mx);
  }
  cout << ans << endl;
}