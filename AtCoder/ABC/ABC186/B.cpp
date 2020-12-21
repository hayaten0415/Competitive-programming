#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int grid[100][100];

int main() {
  int h, w;
  cin >> h >> w;
  int mn = 1000;
  ll ans = 0;
  rep(i, h){
    rep(j, w){
      cin >> grid[i][j];
      chmin(mn, grid[i][j]);
    }
  }
  rep(i, h){
    rep(j, w){
      ans += grid[i][j] - mn;
    }
  }
  cout << ans << endl;
}