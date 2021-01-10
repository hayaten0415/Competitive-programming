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

ll dp[50010][2];

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n) cin >> A[i] >> B[i];
  dp[0][0] = 0;
  dp[0][1] = 0;
  rep(i, n){
    dp[i + 1][1] = max(gcd(dp[i][0], B[i]), gcd(dp[i][1], B[i]));
    dp[i + 1][0] = max(gcd(dp[i][1], A[i]), gcd(dp[i][0], A[i]));
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
}