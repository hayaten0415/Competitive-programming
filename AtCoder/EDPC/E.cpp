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
  vector<vector<ll>> dp(N + 1, vector<ll>(100001, 10000000001));
  dp[0][0] = 0;
  for (int i = 1; i < N + 1; i++){
    for (int j = 0; j < 100001; j++){
      if(j - v[i] >= 0){
        dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
      }else {
        dp[i][j] = min(dp[i][j], dp[i - 1][j]);
      }
    }
  }
  int ans = 100000;
  while(dp[N][ans] > W)ans--;
  cout << ans << endl;
  return 0;
}