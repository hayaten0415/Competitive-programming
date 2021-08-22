#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
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
const auto INF = numeric_limits<T>::max()/2;
using mint = modint998244353;

mint dp[1001][(1 << 10)][10];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  //初期値
  rep(i, n){
    ll b = s[i] - 'A';
    dp[i + 1][1 << b][b]++;
  }
  rep(i, n){
    ll b = s[i] - 'A';
    rep(j, (1 << 10))rep(k, 10){
      dp[i+1][j][k] += dp[i][j][k];
      if(b == k){
        dp[i + 1][j][k] += dp[i][j][k];
      }else{
        if(j & (1 << b))continue;
        dp[i + 1][j | (1 << b)][b] += dp[i][j][k];
      }
    }
  }
  mint ans = 0;
  rep(i, (1 << 10))rep(j, 10){
    ans += dp[n][i][j];
  }
  cout << ans.val() << endl;
}