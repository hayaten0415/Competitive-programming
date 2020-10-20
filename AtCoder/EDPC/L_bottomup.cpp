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


ll dp[3300][3000];
ll a[3200];
bool visited[3300][3300];

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> a[i];
  for(int width = 1;width <= n;width++){
    for (int l = 0; l + width <= n; l++){
      int r = l + width;
      if(width % 2 == n % 2){
        dp[l][r] = max(dp[l + 1][r] + a[l], dp[l][r-1] + a[r-1]);
      }else{
        dp[l][r] = min(dp[l + 1][r] - a[l], dp[l][r - 1] - a[r - 1]);
      }
    }
  }
  cout << dp[0][n] << endl;
}