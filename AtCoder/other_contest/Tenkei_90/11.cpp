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
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, long long>;
using PP = pair<int, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll dp[5005][5005];

int main() {
  int n;
  cin >> n;
  vector<PP> dcs(n);
  rep(i, n){
    int d, c;
    ll s;
    cin >> d >> c >> s;
    dcs[i] = {d, {c, s}};
  }
  sort(ALL(dcs));
  rep(i, n){
    for (int j = 0; j <= 5000; j++){
      if(j < dcs[i].second.first || j > dcs[i].first){
        chmax(dp[i+1][j], dp[i][j]);
      }else{
        chmax(dp[i+1][j], max(dp[i][j], dp[i][j - dcs[i].second.first] + dcs[i].second.second));
      }
    }
  }
  ll ans = 0;
  rep(i, 5001){
    chmax(ans, dp[n][i]);
  }
  cout << ans << endl;
}