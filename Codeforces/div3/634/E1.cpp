#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int n;
  cin >> n;
  vector<vector<int>> num(26, vector<int>(n));
  vector<vector<int>> num_sum(26, vector<int>(n+1));
  rep(i, n){
    int d;
    cin >> d;
    d--;
    num[d][i]++;
  }
  rep(j, 26)rep(i, n){
    num_sum[j][i + 1] = num_sum[j][i] + num[j][i];
  }
  //rep(j, 26)rep(i, n+1){
  //  cout << num_sum[j][i] << (i == n ? "\n" : " ");
  //}
  int ans = 0;
  rep(i, n+1){
    for (int j = i + 1; j <= n; j++){
      int tmp1 = 0;
      int tmp2 = 0;
      if(i == 0 || j == n){
        rep(d, 26){
          chmax(ans, num_sum[d][n]);
        }
      }else{
        rep(d, 26){
          chmax(tmp1, min(num_sum[d][i], num_sum[d][n] - num_sum[d][j]) * 2);
          chmax(tmp2, num_sum[d][j] - num_sum[d][i]);
        }
        chmax(ans, tmp1 + tmp2);
      }
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}