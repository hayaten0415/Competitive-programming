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
//i番目でmodkが次どのindexか
int nx[3050][3050];

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), s(n + 1);
  rep(i, n) cin >> a[i];
  rep(i, n){
    s[i + 1] = s[i] + a[i];
  }
  auto prev_calc = [&](){
    for (int k = 1; k <= n; k++){
      vector<ll> s_tmp = s;
      rep(i, n + 1) s_tmp[i] = (s[i] % k);
      vector<int> ind(k);
      rep(i, k) ind[i] = -1;
      for (int i = n; i >= 0; i--){
        nx[i][k] = ind[s_tmp[i]];
        ind[s_tmp[i]] = i;
      }
    }
  };
  prev_calc();
  dp[0][0] = 1;
  mint ans = 0;
  rep(i, n){
    rep(j, i+1){
      if(nx[i][j+1] == -1)continue;
      if(nx[i][j+1] == n)ans += dp[i][j];
      dp[nx[i][j + 1]][j + 1] += dp[i][j];
      dp[nx[i][j + 1]][j] += dp[i][j];
    }
  }
  cout << ans.val() << endl;
}