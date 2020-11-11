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
const ll inf = (1LL << 20);

int main() {
  int w, h;
  cin >> w >> h;
  int x, y;
  cin >> x >> y;
  vector<vector<ll>> grid(h, vector<ll>(w, 0));
  rep(i, h){
    rep(j, w){
      cin >> grid[i][j];
      if(grid[i][j] == -1)grid[i][j] = inf;
    }
  }
  vector<vector<ll>> sum(h + 1, vector<ll>(w + 1, 0));
  rep(i, h) rep(j, w) sum[i + 1][j + 1] = sum[i][j + 1] + sum[i + 1][j] - sum[i][j] + grid[i][j];
  ll ans = 100000000000000000;
  for (int i = 1; i < h - y + 1; i++){
    for (int j = 1; j < w - x + 1; j++){
      chmin(ans, sum[i + y - 1][j + x - 1] - sum[i + y - 1][j - 1] - sum[i - 1][j + x - 1] + sum[i - 1][j - 1]);
    }
  }
  cout << ans << "\n";
}