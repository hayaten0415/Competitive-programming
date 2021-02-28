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


int main() {
  int n;
  cin >> n;
  vector<vector<ll>> d(n, vector<ll>(n, 0));
  rep(i, n) rep(j, n) cin >> d[i][j];
  vector<vector<ll>> sum(n+1, vector<ll>(n+1, 0));
  rep(i, n) rep(j, n) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + d[i][j];
  //左上[sx, sy], 右下(gx, gy)の矩形内の和を求める(半開区間)
  int ans = sum[gx][gy] - sum[sx][gy] - sum[gx][sy] + sum[sx][sy];
}