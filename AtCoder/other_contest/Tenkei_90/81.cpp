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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<ll>> d(5000, vector<ll>(5000, 0));
  vector<vector<ll>> sum(5001, vector<ll>(5001, 0));
  rep(i, n){
    int a, b;
    cin >> a >> b;
    a--, b--;
    d[a][b]++;
  }
  rep(i, 5000) rep(j, 5000) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + d[i][j];
  //左上[sx, sy], 右下(gx, gy)の矩形内の和を求める(半開区間)
  ll ans = 0;
  for (int i = 0; i + k+1 <= 5000; i++)for (int j = 0; j + k+1 <= 5000; j++){
    chmax(ans, sum[i + k+1][j + k+1] - sum[i][j + k+1] - sum[i + k+1][j] + sum[i][j]);
  }
  cout << ans << endl;
}