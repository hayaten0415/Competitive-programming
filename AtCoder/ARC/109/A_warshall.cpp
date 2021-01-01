#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = (1 << 25);

int main() {
  vector<vector<int>> dist(200, vector<int>(200, INF));
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  a--, b--;
  rep(i, 200){
    dist[i][i] = 0;
  }
  rep(i, 100){
    dist[i][i + 100] = x;
    dist[i + 100][i] = x;
  }
  rep(i, 99){
    dist[i][i + 1] = y;
    dist[i + 1][i] = y;
    dist[i + 100][i + 101] = y;
    dist[i + 101][i + 100] = y;
    dist[i+1][i + 100] = x;
    dist[i + 100][i+1] = x;
  }
  for (int i = 0; i < 200; i++)     // 経由する頂点
    for (int j = 0; j < 200; j++)   // 開始頂点
      for (int k = 0; k < 200; k++) // 終端
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
  cout << dist[a][b+100] << endl;
}