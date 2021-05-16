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
long double dp[301][301][301];

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> B(3);
  rep(i, n){
    cin >> A[i];
    A[i]--;
    B[A[i]]++;
  }
  rep(i, n+1)rep(j, n+1)rep(k, n+1)dp[i][j][k] = 1.0L;
  dp[0][0][0] = 0.0L;
  rep(k, n+1)rep(j, n+1)rep(i, n+1){
    if(i + j + k > 0 && i + j + k <= n){
      if(i > 0){
        dp[i][j][k] += dp[i - 1][j][k] * i / (long double)(n);
      }
      if(j > 0){
        dp[i][j][k] += dp[i + 1][j-1][k] * j / (long double)(n);
      }
      if(k > 0){
        dp[i][j][k] += dp[i][j+1][k-1] * k / (long double)(n);
      }
      dp[i][j][k] *= (long double)1.0L * (long double)(n) / (long double)(i + j + k);
    }
  }
  cout << fixed << setprecision(10) << dp[B[0]][B[1]][B[2]] << endl;
}