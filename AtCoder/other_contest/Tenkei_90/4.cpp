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

int A[2000][2000];
int A_column_sum[2000][2000];
int A_row_sum[2000][2000];
int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h){
    rep(j, w){
      if(j == 0)A_column_sum[i][j] = A[i][j];
      else A_column_sum[i][j] = A_column_sum[i][j-1] + A[i][j];
    }
  }
  rep(i, w){
    rep(j, h){
      if(j == 0)A_row_sum[j][i] = A[j][i];
      else A_row_sum[j][i] = A_row_sum[j-1][i] + A[j][i];
    }
  }
  rep(i, h){
    rep(j, w){
      cout << A_row_sum[h-1][j] + A_column_sum[i][w-1] - A[i][j] << (j == w - 1 ? "\n" : " ");
    }
  }
}