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

ll dp[65][2];
int main() {
  int n;
  cin >> n;
  ll ans = (1LL << (n + 1));
  vector<string> str(n);
  dp[0][0] = 1;
  dp[0][1] = 1;
  rep(i, n) cin >> str[i];
  rep(i, n){
    if(str[i] == "AND"){
      dp[i + 1][1] = dp[i][1];
      dp[i + 1][0] = dp[i][0] * 2 + dp[i][1];
    }else{
      dp[i + 1][1] = dp[i][1] * 2 + dp[i][0];
      dp[i + 1][0] = dp[i][0];
    }
  }
  cout << dp[n][1] << endl;
}