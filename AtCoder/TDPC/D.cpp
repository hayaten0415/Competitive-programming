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

//dp[i][j][s][k] i番目まで見たときに2がj個掛けられ、3がs個掛けられ、5がk個掛けられている値の確率
double dp[101][65][51][30];

int main() {
  int n;
  ll d;
  cin >> n >> d;
  dp[0][0][0][0] = 1.0;
  int two = 0, three = 0, five = 0;
  double ans = 0.0;
  while(d % 5L == 0){
    five++;
    d /= 5L;
  }
  while(d % 3L == 0){
    three++;
    d /= 3L;
  }
  while(d % 2L == 0){
    two++;
    d /= 2L;
  }
  if(d != 1){
    cout << fixed << setprecision(9) << ans << endl;
    return 0;
  }
  rep(i, n){
    rep(j, two+1){
      rep(s, three + 1){
        rep(k, five+1){
          //1の時
          dp[i + 1][j][s][k] += dp[i][j][s][k] * (1.0 / 6.0);
          //2の時
          dp[i + 1][min(j + 1, two)][s][k] += dp[i][j][s][k] * (1.0 / 6.0);
          //3の時
          dp[i + 1][j][min(s+1, three)][k] += dp[i][j][s][k] * (1.0 / 6.0);
          //4の時
          dp[i + 1][min(j + 2, two)][s][k] += dp[i][j][s][k] * (1.0 / 6.0);
          //5の時
          dp[i + 1][j][s][min(k+ 1, five)] += dp[i][j][s][k] * (1.0 / 6.0);
          //6の時
          dp[i + 1][min(j + 1, two)][min(s+1, three)][k] += dp[i][j][s][k] * (1.0 / 6.0);
        }
      }
    }
  }
  cout << fixed << setprecision(9) << dp[n][two][three][five] << endl;
}