#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef vector<vector<int>> Matrix;
Matrix dist; // グラフの距離を格納した2次元配列（隣接行列）
          // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）
const int INF = 100000000;
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
  vector<int> res;
  rep(i, n) dist[i][i] = 0;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    dist[a][b] = 1;
    dist[b][a] = 1;
  }
  warshall_floyd(n);
  rep(i,n){
    int ans = 0;
    rep(j ,n){
      if(dist[i][j] == 2) ans++;
      if(j == n-1) cout << ans << endl;
    }
  }
  return 0;
}