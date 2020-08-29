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
  int ans = (1 << 30);
  vector<string> grid(h);
  vector<int> white(h+1, 0), blue(h+1, 0), red(h+1, 0);
  rep(i, h) cin >> grid[i];
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == 'W')white[i+1]++;
      else if (grid[i][j] == 'B')blue[i+1]++;
      else red[i+1]++;
    }
  }
  rep(i, h){
    white[i + 1] += white[i];
    blue[i + 1] += blue[i];
    red[i + 1] += red[i];
  }
  for (int i = 1; i <= h - 2; i++){
    for (int j = i + 1; j <= h - 1; j++){
      int tmp = 0;
      tmp += blue[i] + red[i];
      tmp += white[j] + red[j] - white[i] - red[i];
      tmp += blue[h] + white[h] - blue[j] - white[j];
      ans = min(ans, tmp);
    }
  }
  cout << ans << endl;
}