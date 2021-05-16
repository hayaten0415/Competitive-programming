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
const int INF = (1 << 30);
int dp[2002][2002];
string s[2002];
int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) cin >> s[i];
  rep(i, h+1)rep(j, w+1) {
      if((i + j) % 2 == 0)dp[i][j] = -INF;
      else dp[i][j] = INF;
  }
  rrep(i, h){
    rrep(j, w){
      if((i + j) % 2 == 0){
            if (i == h - 1 and j == w - 1) {
                dp[i][j] = 0;
            }
            else if (i == h - 1) {
                if (s[i][j + 1] == '+') {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                }
                else {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] - 1);
                }
            }
            else if (j == w - 1) {
                if (s[i + 1][j] == '+') {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
                }
                else {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] - 1);
                }
            }
            else {
                if (s[i][j + 1] == '+') {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] + 1);
                }
                else {
                    dp[i][j] = max(dp[i][j], dp[i][j + 1] - 1);
                }
                if (s[i + 1][j] == '+') {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] + 1);
                }
                else {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j] - 1);
                }
            }
        }
        else {
            if (i == h - 1 and j == w - 1) {
                dp[i][j] = 0;
            }
            else if (i == h - 1) {
                if (s[i][j + 1] == '-') {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] - 1);
                }
            }
            else if (j == w - 1) {
                if (s[i + 1][j] == '-') {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] - 1);
                }
            }
            else {
                if (s[i][j + 1] == '-') {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i][j + 1] - 1);
                }
                if (s[i + 1][j] == '-') {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
                }
                else {
                    dp[i][j] = min(dp[i][j], dp[i + 1][j] - 1);
                }
            }
        }
    }
  }
  if(dp[0][0] > 0){
    cout << "Takahashi" << endl;
  }else if(dp[0][0]< 0){
    cout << "Aoki" << endl;
  }else{
    cout << "Draw" << endl;
  }
}