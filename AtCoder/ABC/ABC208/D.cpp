#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PP = pair<P, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

ll dist2[401][401];
int n;
ll ans = 0;
void warshall_floyd() {
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        dist2[j][k] = min(dist2[j][k], dist2[j][i] + dist2[i][k]);
        if(dist2[j][k] != INF)ans+= dist2[j][k];
      }
    }
  }
}

int main() {
  int m;
  cin >> n >> m;
  rep(i, n) rep(j, n) dist2[i][j] = INF;
  rep(i, n) dist2[i][i] = 0;
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    dist2[a][b] = c;
  }
  warshall_floyd();
  cout << ans << endl;
}