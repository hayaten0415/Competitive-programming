#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const long long mod = 1e9 + 7;

int main(){
  int N, W;
  cin >> N >> W;
  vector<ll> w(N);
  vector<ll> v(N);
  rep(i, N){
    cin >> w[i] >> v[i];
  }
  vector<vector<ll>> dp(N + 1, vector<ll>(W + 1, 0));
  rep(i,N){
    for (int j = 0; j <= W; j++){
      if(j >= w[i]) {
        dp[i + 1][j] = max(dp[i][j - w[i]] + v[i],  dp[i][j]);
      }else {
        dp[i + 1][j] = dp[i][j];
      }
    }
  }
  cout << dp[N][W] << endl;
  return 0;
}