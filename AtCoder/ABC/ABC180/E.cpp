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
const int INF = (1 << 30);

int main() {
  int N;
  cin >> N;
  vector<int> X(N), Y(N), Z(N);
  rep(i, N) cin >> X[i] >> Y[i] >> Z[i];
  int n2 = 1 << N;
  vector<vector<int>> dist(N, vector<int>(N, INF));
  vector<vector<int>> dp(n2, vector<int>(N, INF));
  rep(i, N){
    rep(j, N){
      int now = abs(X[i] - X[j]);
      now += abs(Y[i] - Y[j]);
      now += max(0, Z[j] - Z[i]);
      dist[i][j] = now;
    }
  }
  rep(i, N){
    if(i == 0)continue;
    dp[1 << i][i] = dist[0][i];
  }
  rep(i, n2){
    rep(j, N){
      if(!(i >> j & 1))continue;
      rep(k, N){
        if(i >> k & 1)continue;
        chmin(dp[i | 1 << k][k], dp[i][j] + dist[j][k]);
      }
    }
  }
  cout << dp[n2 - 1][0] << endl;
}