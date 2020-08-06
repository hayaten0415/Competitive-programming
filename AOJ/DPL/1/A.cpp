#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int INF = 100000000;

int main() {
  vector<int> dp(60000, INF);
  dp[0] = 0;
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  rep(i, m) cin >> c[i];
  rep(i, n+1){
    rep(j, m){
      if(i - c[j] >= 0){ 
        dp[i] = min(dp[i], dp[i- c[j]] + 1);
      }
    }
  }
  cout << dp[n] << endl;
}