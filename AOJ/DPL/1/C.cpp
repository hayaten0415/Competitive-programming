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
int dp[102][10010];

int main() {
  int N, W;
  cin >> N >> W;
  vector<int> v(N);
  vector<int> w(N);
  rep(i, N){
    cin >> v[i] >> w[i];
  }
  rep(i, N){
    rep(j, W+1){
      if(j < w[i]){
        dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
      }else{
        dp[i + 1][j] = max(dp[i][j], dp[i+1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[N][W] << endl;
}