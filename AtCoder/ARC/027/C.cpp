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

ll dp[301][301][301];

int main(){
  int N, X, Y;
  cin >> X >> Y >> N;
  vector<int> t(N);
  vector<ll> h(N);
  rep(i, N) cin >> t[i] >> h[i];
  rep(i, N){
    rep(j, X+1)rep(k, Y+1){
      for (int s = max(1, k + t[i] -Y); s <= min(X - j, t[i]); s++){
        chmax(dp[i + 1][j+s][k + t[i] -s], dp[i][j][k] + h[i]);
      }
      chmax(dp[i + 1][j][k], dp[i][j][k]);
    }
  }
  cout << dp[N][X][Y] << endl;
}