#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const long long mod = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  vector<ll> h(n);
  rep(i,n){
    cin >> h[i];
  }
  vector<ll> dp(n + 1, 1000000000000000);
  dp[0] = 0;
  for (int now = 0; now < n; now++){
    if(now + 1 < n){
      dp[now + 1] = min(dp[now + 1], dp[now] + abs(h[now + 1] - h[now]));
    }
    if(now + 2 < n){
      dp[now + 2] = min(dp[now + 2], dp[now] + abs(h[now + 2] - h[now]));
    }
    
  }
  cout << dp[n - 1] << endl;
  return 0;
}