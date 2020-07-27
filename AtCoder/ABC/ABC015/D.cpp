#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll dp[60][10010][60];

int main() {
  int w, n, k;
  cin >> w >> n >> k;
  vector<int> a(n);
  vector<int> b(n);
  rep(i, n){
    cin >> a[i] >> b[i];
  }
  for (int i = 1; i <= n; i++){
    for (int j = 1; j <= w; j++){
      for (int s = 1; s <=k; s++){
        if(j - a[i-1] >= 0){
          dp[i][j][s] = max(dp[i - 1][j][s], dp[i - 1][j - a[i-1]][s - 1] + b[i-1]);
        }else{
          dp[i][j][s] = dp[i - 1][j][s];
        }
      }
    }
  }
  cout << dp[n][w][k] << endl;
}