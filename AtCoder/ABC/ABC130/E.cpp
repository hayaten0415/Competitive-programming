#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max();
using mint = modint1000000007;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  vector<vector<mint>> dp(n + 1, vector<mint>(m + 1, 0));
  for (int i = 1; i <= n;i++){
    for (int j = 1; j <= m; j++){
      if(A[i-1] == B[j-1]){
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + 1;
      }else{
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i-1][j-1];
      }
    }
  }
  mint ans = dp[n][m];
  ans++;
  cout << ans.val() << endl;
}