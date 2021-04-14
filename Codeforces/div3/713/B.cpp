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
  rep(i, n) cin >> grid[i];
  vector<P> sq;
  rep(i, n)rep(j, n){
    if(grid[i][j] == '*'){
      sq.pb({i, j});
    }
  }
  if(sq[0].first == sq[1].first){
    if(sq[0].first > 0){
      grid[sq[0].first - 1][sq[0].second] = '*';
      grid[sq[1].first - 1][sq[1].second] = '*';
    }else{
      grid[sq[0].first + 1][sq[0].second] = '*';
      grid[sq[1].first + 1][sq[1].second] = '*';
    }
  }else if(sq[0].second == sq[1].second){
    if(sq[0].second > 0){
      grid[sq[0].first][sq[0].second-1] = '*';
      grid[sq[1].first][sq[1].second-1] = '*';
    }else{
      grid[sq[0].first][sq[0].second + 1] = '*';
      grid[sq[1].first][sq[1].second + 1] = '*';
    }
  }else{
    grid[sq[1].first][sq[0].second] = '*';
    grid[sq[0].first][sq[1].second] = '*';
  }
  rep(i, n) cout << grid[i] << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}