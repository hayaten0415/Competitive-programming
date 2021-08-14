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
vector<int> left_tmp, left_max, right_tmp;

void LIS_left(vector<int> &A){
  int n = A.size();
  vector<int> dp(n, INF);
  rep(i, n){
    auto it = lower_bound(ALL(dp), A[i]);
    *it = A[i];
    int d = lower_bound(ALL(dp), INF) - dp.begin();
    left_tmp[i+1] = d;
    left_max[i+1] = dp[d - 1];
  }
}
void LIS_right(vector<int> &A){
  int n = A.size();
  vector<int> dp(n, INF);
  rrep(i, n){
    auto it = lower_bound(ALL(dp), A[i]);
    if(A[i] < left_max[i]){
      *it = A[i];
    }
    int d = lower_bound(ALL(dp), INF) - dp.begin();
    right_tmp[i] = d;
  }
}


int main() {
  int n;
  cin >> n;
  left_tmp.resize(n + 1);
  right_tmp.resize(n + 1);
  left_max.resize(n + 1);
  left_max[0] = INF;
  right_tmp[n] = 0;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  LIS_left(A);
  LIS_right(A);
  int ans = 0;
  rep(i, n+1){
    chmax(ans, left_tmp[i] + right_tmp[i]);
  }
  cout << ans << endl;
}