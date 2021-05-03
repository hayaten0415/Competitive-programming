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
ll dp[1001][8];

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(bit, 8){
    if(s[0] == 'J'){
      if(bit & 1)dp[0][bit]++;
    }
    if(s[0] == 'O'){
      if((bit & 1) && (bit & 2))dp[0][bit]++;
    }
    if(s[0] == 'I'){
      if((bit & 1) && (bit & 4))dp[0][bit]++;
    }
  }
  for (int i = 1; i < n; i++){
    rep(bit1, 8)rep(bit2, 8){
      if((bit1 & bit2) == 0)continue;
      if(s[i] == 'J'){
        if((bit2 & 1)){
          dp[i][bit2] += dp[i - 1][bit1];
          dp[i][bit2] %= 10007;
        }
      }
      if(s[i] == 'O'){
        if((bit2 & 2)){
          dp[i][bit2] += dp[i - 1][bit1];
          dp[i][bit2] %= 10007;
        }
      }
      if(s[i] == 'I'){
        if(bit2 & 4){
          dp[i][bit2] += dp[i - 1][bit1];
          dp[i][bit2] %= 10007;
        }
      }
    }
  }
  ll ans = 0;
  rep(i, 8){
    ans += dp[n - 1][i];
    ans %= 10007;
  }
  cout << ans << endl;
}