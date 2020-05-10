#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
const long long INF = 100000000000;
typedef long long ll;
typedef vector<vector<ll>> Matrix;
Matrix dist; // グラフの距離を格納した2次元配列（隣接行列）
             // d[u][v]は辺e=(u,v)のコスト（辺が存在しない場合はINF、ただしd[i][i]=0）

//ワーシャルフロイド法
void warshall_floyd(int n){                                 // nは頂点数
  for (int i = 0; i < n; i++)     // 経由する頂点
    for (int j = 0; j < n; j++)   // 開始頂点
      for (int k = 0; k < n; k++) // 終端
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

int main() {
  int h, w;
  cin >> h >> w;
  ll ans = 0;
  dist = Matrix(10, vector<ll>(10));
  rep(i,10){
    rep(j,10){
      cin >> dist[i][j];
    }
  }
  warshall_floyd(10);
  rep(i,h){
    rep(j,w){
      int num;
      cin >> num;
      if(num == 1 || num == -1) continue;
      ans += dist[num][1];
    }
  }
  cout << ans << endl;
}