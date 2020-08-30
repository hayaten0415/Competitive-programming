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
const int INF = (1 << 30);

int main() {
  int h, n;
  cin >> h >> n;
  vector<int> dp(22222, INF);
  vector<int> A(n);
  vector<int> B(n);
  rep(i, n){
    cin >> A[i] >> B[i];
  }
  dp[0] = 0;
  rep(i, n){
    rep(j, 22222){
      if(j < A[i]){
        continue;
      }else{
        dp[j] = min(dp[j], dp[j - A[i]] + B[i]);
      }
    }
  }
  int ans = INF;
   for(int i=h;i<22222;i++) chmin(ans, dp[i]);
   cout << ans << endl;
}