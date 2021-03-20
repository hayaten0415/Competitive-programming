#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int n, m;
ll L;
const ll INF = (1LL << 60);
ll dist[300][300];
ll fuel[300][300];

void warshall_floyd() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      if(dist[j][i]== INF)continue;
      for (int k = 0; k < n; k++){
        if(dist[i][k]== INF)continue;
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }
}
void warshall_floyd2() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        fuel[j][k] = min(fuel[j][k], fuel[j][i] + fuel[i][k]);
      }
    }
  }
}


int main(){
  cin >> n >> m >> L;
  rep(i, n) rep(j, n){
    dist[i][j] = INF;
    fuel[i][j] = INF;
  }
  rep(i, n){
    dist[i][i] = 0;
    fuel[i][i] = 0;
  }
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  warshall_floyd();
  rep(i, n)rep(j, n){
    if(dist[i][j] <= L)fuel[i][j] = 1;
  }
  warshall_floyd2();
  int q;
  cin >> q;
  rep(i, q){
    int s, t;
    cin >> s >> t;
    s--, t--;
    ll ans = fuel[s][t] - 1;
    if(fuel[s][t] == INF)ans = -1;
    cout << ans << endl;
  }
}