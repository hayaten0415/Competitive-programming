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
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);
ll d[17][17];

int main() {
  int n;
  ll k;
  cin >> n >> k;
  rep(i, n) rep(j, n) cin >> d[i][j];
  int n2 = (1 << n);
  vector<ll> cost(n2);
  rep(i, n2){
    rep(j, n) for (int s = j + 1; s < n;s++){
      if((i & (1 << j)) && (i & (1 << s))){
        cost[i] += d[j][s];
      }
    }
  }
  vector<ll> dp(n2);
  dp[0] = 0;
  rep(i, n)dp[1 << i] = k;
  rep(S, n2){
    //集合Sの部分集合のうち空集合は飛ばしている。
    for (int T = S; T > 0; T = (T - 1) & S){
      int rest = S ^ T;
      chmax(dp[S], (dp[rest] - cost[S] + cost[T] + cost[rest] + k));
    }
  }
  cout << dp[n2-1] << endl;
}