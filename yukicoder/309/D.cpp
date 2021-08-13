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
using mint = modint998244353;

int main(){
  int n;
  cin >> n;
  vector<int> A(n);
  vector<vector<mint>> dp(n+1, vector<mint>(20001));
  rep(i, n){
    cin >> A[i];
  }
  dp[0][10000] = 1;
  rep(i, n){
    rep(j, 20001){
      if(0<= j - A[i] && j - A[i] <= 20000){
        dp[i+1][j] += dp[i][j - A[i]];
      }
      if(0<= j + A[i] && j + A[i] <= 20000){
        dp[i+1][j] += dp[i][j + A[i]];
      }
    }
  }
  mint ans = 0;
  rep(j, 20001){
    if(dp[n][j] == 0)continue;
    mint num = abs(10000 - j);
    ans += num * dp[n][j];
  }
  cout << ans.val() << endl;
}