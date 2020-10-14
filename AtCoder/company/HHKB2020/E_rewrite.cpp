#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using mint = modint1000000007;

int Left[2100][2100], Right[2100][2100], Up[2100][2100], Down[2100][2100];

int main() {
  mint ans = 0;
  mint s = 2;
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  int k = 0;
  rep(i, h)rep(j,w){
    if(grid[i][j] == '.')k++;
  }
  rep(i, h){
    int now = 0;
    rep(j, w){
      if (grid[i][j] == '#') now = 0;
      else now++;
      Left[i][j] = now;
    }
  }
  rep(i, h){
    int now = 0;
    rrep(j, w){
      if (grid[i][j] == '#') now = 0;
      else now++;
      Right[i][j] = now;
    }
  }
  rep(j, w){
    int now = 0;
    rep(i, h){
      if (grid[i][j] == '#') now = 0;
      else now++;
      Up[i][j] = now;
    }
  }
  rep(j, w){
    int now = 0;
    rrep(i, h){
      if (grid[i][j] == '#') now = 0;
      else now++;
      Down[i][j] = now;
    }
  }
  rep(i,h){
    rep(j,w){
      if(grid[i][j] == '#')continue;
      int num = Left[i][j] + Right[i][j] + Up[i][j] + Down[i][j] - 3;
      int x = k - num;
      ans += s.pow(k);
      ans -= s.pow(x);
    }
  }
  cout << ans.val() << endl;
}