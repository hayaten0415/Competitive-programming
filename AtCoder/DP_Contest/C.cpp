#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
const long long mod = 1e9 + 7;

int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n);
  rep(i, n){
    cin >> a[i] >> b[i] >> c[i];
  }
  vector<vector<int>> dp(n, vector<int>(3));
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];
  rep(i ,n -1){
    dp[i + 1][0] = max(dp[i][1] + a[i + 1], dp[i][2] + a[i + 1]);
    dp[i + 1][1] = max(dp[i][0] + b[i + 1], dp[i][2] + b[i + 1]);
    dp[i + 1][2] = max(dp[i][0] + c[i + 1], dp[i][1] +c[i + 1]);
  }
  cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << endl;
  return 0;
}