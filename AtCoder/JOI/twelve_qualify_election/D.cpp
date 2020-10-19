#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
ll dp[220][220];


int main() {
  int d, n;
  cin >> d >> n;
  vector<int> X(d), C(n);
  vector<vector<int>> ava_close_list(61);
  rep(i, d) cin >> X[i];
  rep(i, n){
    int a, b;
    cin >> a >> b >> C[i];
    for (int j = a; j <= b; j++){
      ava_close_list[j].emplace_back(i);
    }
  }
  rep(i, d-1){
    for(int j : ava_close_list[X[i]]){
      for(int k : ava_close_list[X[i+1]]){
        chmax(dp[i + 1][k], dp[i][j] + abs(C[k] - C[j]));
      }
    }
  }
  ll ans = 0;
  rep(i, n){
    chmax(ans, dp[d - 1][i]);
  }
  cout << ans << endl;
}