#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<ll> dp(n, 100000000000000);
  rep(i, n) cin >> a[i];
  dp[0] = 0;
  rep(i,n){
    if(i + 1 < n){
      dp[i + 1] = min(dp[i + 1], dp[i] + abs(a[i + 1] - a[i]));
    }
    if(i + 2 < n){
      dp[i + 2] = min(dp[i + 2], dp[i] + abs(a[i + 2] - a[i]));
    }
  }
  cout << dp[n-1] << endl;
}
