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

ll dp[101][1000];
int main() {
  int n;
  cin >> n;
  vector<int> X(n);
  rep(i, n) cin >> X[i];
  dp[0][X[0]] = 1;
  for (int i =0; i < n - 2; i++){
    for (int k = 0; k < 21; k++){
      if(k - X[i+1] >=0){
        dp[i + 1][k] += dp[i][k - X[i+1]];
      }
      if (k + X[i + 1] <= 20){
        dp[i + 1][k] += dp[i][k + X[i + 1]];
      }
    }
  }
  cout << dp[n-2][X[n-1]] << endl;
}