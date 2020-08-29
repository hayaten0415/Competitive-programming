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
  vector<vector<int>> ans(h, vector<int>(w));
  rep(i, h) cin >> grid[i];
  rep(i, h){
    int minute = -1;
    rep(j, w){
      if(grid[i][j] == 'c'){
        minute = 0;
        ans[i][j] = 0;
      }else{
        if(minute == -1)ans[i][j] = -1;
        else ans[i][j] = minute + 1, minute++;
      }
    }
  }
  rep(i, h){
    rep(j, w){
      cout << ans[i][j] << (j == w - 1 ? "\n" : " ");
    }
  }
}