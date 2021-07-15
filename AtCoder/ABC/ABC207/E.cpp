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

//最後の区切りがiで次がj番目
mint dp[3050][3050];
//mod jでkのものの通り数
mint dps[3050][3050];

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), s(n + 1);
  rep(i, n) cin >> A[i];
  rep(i, n){
    s[i + 1] = s[i] + A[i];
  }
  mint ans = 0;
  dp[0][1] = 1;
  dps[1][0] = 1;
  for (int i = 1; i <= n; i++){
    for (int j = i; j >= 1; j--){
      dp[i][j + 1] = dps[j][s[i] % j];
      dps[j + 1][s[i] % (j + 1)] += dp[i][j + 1];
    }
  }
  rep(i, n + 2){
    if (i == 0)continue;
    ans += dp[n][i];
  }
  cout << ans.val() << endl;
}