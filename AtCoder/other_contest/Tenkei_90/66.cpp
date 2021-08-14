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

double dp[100];

int main() {
  int n;
  cin >> n;
  vector<int> L(n), R(n);
  rep(i, n) cin >> L[i] >> R[i];
  double ans = 0.0;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j <n; j++){
      int cnt = 0, all = 0;
      for (int s = L[i]; s <= R[i]; s++){
        for (int k = L[j]; k <= R[j]; k++){
          if(s > k){
            cnt++;
          }
          all++;
        }
      }
      ans += (double)cnt / all;
    }
  }
  cout << fixed << setprecision(9) << ans << endl;
}