#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
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

mint dp[300001][3];

int main() {
  ll n;
  cin >> n;
  //n *= 3;
  //dp[0][0] = 1;
  //dp[0][1] = 1;
  //rep(i, n){
  //  rep(j, 3){
  //    if((i+1) % 3 == 0 && j == 2){
  //      continue;
  //    }
  //    rep(k, 3){
  //      if(j == k)continue;
  //      dp[i + 1][j] += dp[i][k];
  //    }
  //  }
  //}
  //mint ans = dp[n-1][0] + dp[n-1][1] + dp[n-1][2];
  mint ans = mint(5).pow(n - 1);
  ans *= 8;
  cout << ans.val() << endl;
}