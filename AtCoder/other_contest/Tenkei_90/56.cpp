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
  int n, s;
  cin >> n >> s;
  vector<vector<int>> dp(n + 1, vector<int>(s, 0));
  vector<vector<bool>> dp_ok(n + 1, vector<bool>(s, false));
  dp_ok[0][0] = true;
  vector<int> A(n), B(n);
  rep(i, n) cin >>A[i] >> B[i];
  vector<vector<char>> pre(n + 1, vector<char>(s + 1, '-'));
  rep(i, n)rep(j, s+1){
    if(!dp_ok[i][j])continue;
    if(j + A[i] <= s){
      dp_ok[i+1][j + A[i]] = true;
      pre[i + 1][j + A[i]] = 'A';
    }
    if(j + B[i] <= s){
      dp_ok[i+1][j + B[i]] = true;
      pre[i + 1][j + B[i]] = 'B';
    }
  }
  if(dp_ok[n][s]){
    string ans = "";
    int num = s;
    rrep(i, n){
      ans.pb(pre[i+1][num]);
      if(pre[i+1][num] == 'A')num -=A[i];
      else if(pre[i+1][num] == 'B') num -=B[i];
    }
    reverse(ALL(ans));
    cout << ans << endl;
  }else{
    cout << "Impossible" << endl;
  }
}