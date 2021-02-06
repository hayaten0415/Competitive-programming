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

int d[30][30][10];
int sum[31][31][10];

int main() {
  int n, m, p;
  cin >> n >> m >> p;
  vector<string> grid(n);
  rep(i, n) cin >> grid[i];
  rep(i, n)rep(j, m){
    int c = grid[i][j] - '0';
    d[i][j][c]++;
  }
  int ans = 0;
  rep(i, n) rep(j, m) rep(k, 10) sum[i + 1][j + 1][k] = sum[i][j + 1][k] + sum[i + 1][j][k] - sum[i][j][k] + d[i][j][k];
  rep(i, n)rep(j, m){
    rep(k, 30){
      if(i + k >=n || j + k >= m)break;
      int ni = i + k + 1, nj = j + k + 1;
      rep(m ,10){
        int sum_tmp = sum[ni][nj][m] - sum[ni][j][m] - sum[i][nj][m] + sum[i][j][m];
        int l = (k + 1) * (k + 1);
        if(l- sum_tmp <= p)chmax(ans, k+1);
      }
    }
  }
  cout << ans << endl;
}