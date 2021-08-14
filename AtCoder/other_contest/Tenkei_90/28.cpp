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

int sum[1003][1003];
int area[100002];

int main() {
  int n;
  cin >> n;
  rep(i, n){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    sum[b][a]++;
    sum[d][a]--;
    sum[b][c]--;
    sum[d][c]++;
  }
  rep(i, 1001) for (int j = 1; j <= 1000; j++) sum[i][j] += sum[i][j-1];
  for (int i = 1; i <= 1000; i++)rep(j, 1001) sum[i][j] += sum[i-1][j];
  rep(i, 1001)rep(j, 1001)area[sum[i][j]]++;
  for (int i = 1; i <= n; i++){
    cout << area[i] << endl;
  }
}