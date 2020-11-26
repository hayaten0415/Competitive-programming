#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; --i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
double dp[101][101][101];
const int K = 100;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  rrep(i, K){
    rrep(j, K){
      rrep(k, K){
        if(i + j + k == 0)continue;
        double now = 0;
        now += dp[i + 1][j][k] * i;
        now += dp[i][j+1][k] * j;
        now += dp[i][j][k + 1] * k;
        dp[i][j][k] = now / (i + j + k) + 1;
      }
    }
  }
  double ans = dp[a][b][c];
  cout << fixed << setprecision(15) << ans << endl;
}