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

int main(){
  int n, m, r;
  cin >> n >> m >> r;
  vector<ll> R(r);
  rep(i, r){
    cin >> R[i];
    R[i]--;
  }
  dist = Matrix(n, vector<ll>(n, INF));
  vector<ll> a(m), b(m), c(m);
  for (int i = 0; i < n; i++) dist[i][i] = 0;
  for (int i = 0; i < m; i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--;
    b[i]--;
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
  }
  //next_permutationはあらかじめソートしておかないと全部探索してくれない
  sort(R.begin(), R.end());
  warshall_floyd(n);
  ll ans = 100000000000;
  do{
    ll dis = 0;
    for(int i = 1; i < r; i++){
      dis += dist[R[i-1]][R[i]];
    }
    ans = min(ans, dis);
  } while (next_permutation(R.begin(), R.end()));
  cout << ans << endl;
}