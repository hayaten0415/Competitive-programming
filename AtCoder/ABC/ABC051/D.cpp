#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
const int INF = 10000000;
typedef long long ll;
typedef vector<vector<int>> Matrix;
Matrix dist; // グラフの距離を格納した2次元配列（隣接行列）
          // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

//ワーシャルフロイド法
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
  vector<int> a(m), b(m), c(m);
  for (int i = 0; i < n; i++) dist[i][i] = 0;
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--; b[i]--;
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
  }
  warshall_floyd(n);
  int ans = m;
  for (int i = 0; i < m; i++){
    bool shortest = false;
    for (int j = 0; j < n; j++){
      if(dist[j][b[i]] == dist[j][a[i]] + c[i]) shortest = true;
    }
    if(shortest)ans--;
  }
  cout << ans << endl;
}