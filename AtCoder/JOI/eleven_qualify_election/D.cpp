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
const int MOD = 10000;
ll dp[120][3][3];

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> source(n, -1);
  rep(i, k){
    int a, b;
    cin >> a >> b;
    a--, b--;
    source[a] = b;
  }
  if(source[0]== -1){
    rep(k, 3){
      dp[0][k][1] = 1;
    }
  }else{
    dp[0][source[0]][1] = 1;
  }
  for (int i = 1; i < n; i++){
    if(source[i] == -1){
      rep(j, 3){
        rep(k, 3){
          if(j == k){
            dp[i][j][2] += dp[i - 1][k][1];
            dp[i][j][2] %= MOD;
          }else{
            rep(s, 3){
              dp[i][j][1] += dp[i - 1][k][s];
              dp[i][j][1] %= MOD;
            }
          }
        }
      }
    }else{
      rep(k, 3){
        if(source[i] == k){
            dp[i][source[i]][2] += dp[i - 1][source[i]][1];
            dp[i][source[i]][2] %= MOD;
        }else{
          rep(s, 3){
            dp[i][source[i]][1] += dp[i - 1][k][s];
            dp[i][source[i]][1] %= MOD;
          }
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 3){
    rep(k, 3){
      ans += dp[n - 1][i][k];
      ans %= MOD;
    }
  }
  cout << ans << endl;
}