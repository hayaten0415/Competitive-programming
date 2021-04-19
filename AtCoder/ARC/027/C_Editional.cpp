#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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

ll dp[301][301][601];

int main(){
  int N, X, Y;
  cin >> X >> Y >> N;
  vector<int> t(N);
  vector<ll> h(N);
  rep(i, N) cin >> t[i] >> h[i];
  for (int i = 0; i < N; i++){
    rep(j, i + 1) for (int k = 0; k <= X + Y; k++){
      if(k + t[i] -1 <=X + Y){
        chmax(dp[i + 1][j + 1][k + t[i] - 1], dp[i][j][k] + h[i]);
      }
      chmax(dp[i+1][j][k], dp[i][j][k]);
    }
  }
  ll ans = 0;
  for (int i = 0; i <= min(X, N); i++){
    for (int j = 0; j <= X + Y - i; j++){
      chmax(ans, dp[N][i][j]);
    }
  }
  cout << ans << endl;
}