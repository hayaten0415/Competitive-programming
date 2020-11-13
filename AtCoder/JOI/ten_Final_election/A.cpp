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
  int h, w, q;
  cin >> h >> w >> q;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  vector<vector<int>> J(h, vector<int>(w, 0)), O(h, vector<int>(w, 0)), I(h, vector<int>(w, 0));
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == 'J')J[i][j]++;
      if(grid[i][j] == 'O')O[i][j]++;
      if(grid[i][j] == 'I')I[i][j]++;
    }
  }
  vector<vector<int>> sum_J(h + 1, vector<int>(w + 1, 0)), sum_O(h + 1, vector<int>(w + 1, 0)), sum_I(h + 1, vector<int>(w + 1, 0));
  rep(i, h) rep(j, w){
    sum_J[i + 1][j + 1] = sum_J[i][j + 1] + sum_J[i + 1][j] - sum_J[i][j] + J[i][j];
    sum_O[i + 1][j + 1] = sum_O[i][j + 1] + sum_O[i + 1][j] - sum_O[i][j] + O[i][j];
    sum_I[i + 1][j + 1] = sum_I[i][j + 1] + sum_I[i + 1][j] - sum_I[i][j] + I[i][j];
  }
  vector<int> ans_j(q), ans_o(q), ans_i(q);
  rep(s, q){
    int x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    x1--, y1--;
    ans_j[s] = sum_J[y2][x2] - sum_J[y2][x1] - sum_J[y1][x2] + sum_J[y1][x1];
    ans_o[s] = sum_O[y2][x2] - sum_O[y2][x1] - sum_O[y1][x2] + sum_O[y1][x1];
    ans_i[s] = sum_I[y2][x2] - sum_I[y2][x1] - sum_I[y1][x2] + sum_I[y1][x1];
  }
  rep(i, q){
    cout << ans_j[i] << " " << ans_o[i] << " " << ans_i[i] << endl;
  }
}