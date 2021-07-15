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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[2] = {-1, 0};
const int dy[2] = {0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int INF = (1 <<30);

bool dp[80][80][12801];

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> A(h, vector<int>(w));
  vector<vector<int>> B(h, vector<int>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h) rep(j, w) cin >> B[i][j];
  dp[0][0][abs(A[0][0] - B[0][0])] = true;
  rep(i, h)rep(j, w){
    if(i+ 1 < h){
      rep(k, 12801){
        if(!dp[i][j][k])continue;
        dp[i + 1][j][abs(k + abs(A[i + 1][j] - B[i + 1][j]))] = true;
        dp[i + 1][j][abs(k - abs(A[i + 1][j] - B[i + 1][j]))] = true;
      }
    }
    if(j+ 1 < w){
      rep(k, 12801){
        if(!dp[i][j][k])continue;
        dp[i][j+1][abs(k + abs(A[i][j+1] - B[i][j+1]))] = true;
        dp[i][j+1][abs(k - abs(A[i][j + 1] - B[i][j+1]))] = true;
      }
    }
  }
  rep(i, 12801){
    if(dp[h-1][w-1][i]){
      cout << i << endl;
      return 0;
    }
  }
}