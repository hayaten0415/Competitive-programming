#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const long long mod = 1e9 + 7;

int main(){
  int n, k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i,n){
    cin >> h[i];
  }
  vector<ll> dp(n + 1, 1000000000000000);
  dp[0] = 0;
  for (int now = 0; now < n; now++){
    for (int j = 1; j <= k; j++){
      if(now + j <  n){
        dp[now + j] = min(dp[now + j], dp[now] + abs(h[now + j] - h[now]));
      }
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}