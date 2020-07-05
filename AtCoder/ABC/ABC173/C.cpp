#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h, w, k;
  cin >> h >> w >> k;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  int sum = 0;
  int ans = 0;
  rep(i,h){
    rep(j, w){
      if(grid[i][j] == '#')sum++;
    }
  }
  if(sum < k){
    cout << 0 << endl;
    return 0;
  }
  for (int bit1 = 0; bit1 < (1 << h); bit1++){
    for (int bit2 = 0; bit2 < (1 << w); bit2++){
      vector<string> tmp_grid(h);
      tmp_grid = grid;
      int tmp = sum;
      rep(i, h){
        if(bit1 & (1 << i)){
          rep(d, w){
            if(tmp_grid[i][d] == '#'){
              tmp_grid[i][d] = '.';
              tmp--;
            }
          }
        }
      }
      rep(j, w){
        if(bit2 & (1 << j)){
          rep(d, h){
            if(tmp_grid[d][j] == '#'){
              tmp_grid[d][j] = '.';
              tmp--;
            }
          }
        }
      }
      if(tmp == k){
        ans++;
      }
    }
  }
  cout << ans << endl;
}