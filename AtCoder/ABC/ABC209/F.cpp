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
using mint = modint1000000007;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);

mint dp[4010][4010];

int main() {
  int n;
  cin >> n;
  vector<int> H(n);
  rep(i, n) cin >> H[i];
  rep(i, n) dp[0][i] = 1;
  rep(i, n-1){
    vector<mint> sum(n + 1, 0);
    rep(j, n){
      sum[j + 1] = sum[j] + dp[i][j];
    }
    if(H[i] >= H[i+1]){
      rep(j, n-i){
        dp[i + 1][j] += sum[j+1];
      }
    }
    if(H[i] <= H[i+1]){
      rep(j, n-i){
        dp[i + 1][j] += (sum[n-i] - sum[j+1]);
      }
    }
  }
  cout << dp[n - 1][0].val() << endl;
}