#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  int ans = 0;
  vector<string> grid(h);
  vector<vector<int>> cnd(h, vector<int>(w, 0));
  rep(i, h) cin >> grid[i];
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == 'x'){
        for (int ii = i - k; ii <= i + k; ii++){
          if(ii < 0 || h <= ii)continue;
          for (int jj = j - k; jj <= j + k; jj++){
            if(jj < 0 || w <= jj)continue;
            if(abs(i - ii) + abs(j - jj) <= k-1)cnd[ii][jj]++;
          }
        }
      }
    }
  }
  for (int i = k - 1; i <= h - k; i++){
    for (int j = k - 1; j <= w - k; j++){
      if(cnd[i][j] == 0)ans++;
    }
  }
    cout << ans << endl;
}
