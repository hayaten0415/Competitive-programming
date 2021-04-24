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
  vector<string> grid(n);
  vector<vector<bool>> ok(n, vector<bool>(n));
  rep(i, n) cin >> grid[i];
  rep(i, n){
    bool pre_one = false;
    for (int j = n-1; j >= 0; j--){
      if(grid[j][i] == '1'){
        if(j < n-1 & pre_one)ok[j][i] = true;
        if(j == n-1)ok[j][i] = true;
        pre_one = true;
      }else{
        if(!pre_one)ok[j][i] = true;
        pre_one = false;
      }
    }
  }
  rep(i, n){
    bool pre_one = false;
    for (int j = n-1; j >= 0; j--){
      if(grid[i][j] == '1'){
        if(j < n-1 & pre_one)ok[i][j] = true;
        if(j == n-1)ok[i][j] = true;
        pre_one = true;
      }else{
        if(!pre_one & j > 0)ok[i][j] = true;
        if(j == n-1)ok[i][j] = true;
        pre_one = false;
      }
    }
  }
  rep(i, n)rep(j, n){
    if(!ok[i][j] & grid[i][j] == '1'){
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}