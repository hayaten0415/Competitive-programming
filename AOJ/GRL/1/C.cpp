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
const ll INF = (1LL << 40);
int n, m;

struct Edge {
  int from, to;
  ll cost;
};

vector<Edge> v;
ll dist[500];
ll dist2[500][500];
bool negative[500];


void warshall_floyd() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if(dist2[j][i]== INF)continue;
      for (int k = 0; k < n; k++){
        if(dist2[i][k]== INF)continue;
        dist2[j][k] = min(dist2[j][k], dist2[j][i] + dist2[i][k]);
      }
    }
  }
}


int main() {
  cin >> n >> m;
  rep(i, n)rep(j, n)dist2[i][j] = INF;
  rep(i, n) dist2[i][i] = 0;
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    dist2[a][b] = c;
  };
  warshall_floyd();
  bool ng = false;
  rep(i, n){
    if(dist2[i][i] < 0)ng = true;
  }
  if(ng){
    cout << "NEGATIVE CYCLE" << endl;
  }else{
    rep(i, n){
      rep(j, n){
        if(dist2[i][j] == INF){
          cout << "INF" << (j == n - 1 ? "\n" : " ");
        }else{
          cout << dist2[i][j] << (j == n - 1 ? "\n" : " ");
        }
      }
    }
  }
}