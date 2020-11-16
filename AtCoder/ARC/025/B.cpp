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
  vector<vector<int>> black(h, vector<int>(w, 0));
  vector<vector<int>> white(h, vector<int>(w, 0));
  vector<vector<int>> sum_black(h + 1, vector<int>(w + 1, 0));
  vector<vector<int>> sum_white(h + 1, vector<int>(w + 1, 0)); 
  rep(i, h)rep(j,w){
    int k = i + j;;
    if(k % 2 == 0){
      cin >> black[i][j];
    }else{
      cin >> white[i][j];
    }
  }
  rep(i, h) rep(j, w){
    sum_black[i + 1][j + 1] = sum_black[i][j + 1] + sum_black[i + 1][j] - sum_black[i][j] + black[i][j];
    sum_white[i + 1][j + 1] = sum_white[i][j + 1] + sum_white[i + 1][j] - sum_white[i][j] + white[i][j];
  }
  int ans = 0;
  for (int x1 = 0; x1 < h; x1++){
    for (int x2 = x1 + 1; x2 <= h; x2++){
      for (int y1 = 0; y1 < w; y1++){
        for (int y2 = y1 + 1; y2 <= w; y2++){
          int area = (x2 - x1) * (y2 - y1);
          int black_num = sum_black[x2][y2] - sum_black[x1][y2] - sum_black[x2][y1] + sum_black[x1][y1];
          int white_num = sum_white[x2][y2] - sum_white[x1][y2] - sum_white[x2][y1] + sum_white[x1][y1];
          if(black_num == white_num)chmax(ans, area);
        }
      }
    }
  }
  cout << ans << endl;
}