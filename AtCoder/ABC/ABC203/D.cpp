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

int main() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> A(n, vector<int>(n));
  rep(i, n) rep(j, n){
    cin >> A[i][j];
  }
  int left = -1, right = 1e9 + 1;
  auto ok = [&](int mid) {
    vector<vector<int>> d(n, vector<int>(n, 0));
    rep(i, n) rep(j, n) if (A[i][j] <= mid) d[i][j] = 1;
    vector<vector<int>> sum(n + 1, vector<int>(n + 1, 0));
    rep(i, n) rep(j, n) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + d[i][j];
    bool res = false;
    rep(i, n)rep(j, n){
      if(i + k> n || j + k> n)continue;
      int tmp = sum[i+ k][j + k] - sum[i][j + k] - sum[i + k][j] + sum[i][j];
      if(k % 2 == 1){
        if(tmp >= (k * k) / 2 + 1)res = true;
      }else{
        if(tmp >= (k * k) / 2)res = true;
      }
    }
    return res;
  };
  while(right - left > 1){
    int mid = (left + right) / 2;
    if(ok(mid)){
      right = mid;
    }else{
      left = mid;
    }
  }
  cout << right << endl;
}