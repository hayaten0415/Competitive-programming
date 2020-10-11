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

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  int ans = 0;
  rep(i, h){
    rep(j , w-1){
      if(grid[i][j] == grid[i][j+1] &&grid[i][j] == '.')ans++;
    }
  }
  rep(i, w){
    rep(j , h-1){
      if(grid[j][i] == grid[j+1][i] &&grid[j][i] == '.')ans++;
    }
  }
  cout << ans << endl;
}