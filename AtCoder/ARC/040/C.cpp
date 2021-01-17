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
  int n;
  cin >> n;
  vector<string> grid(n);
  rep(i, n) cin >> grid[i];
  int ans = 0;
  rep(i, n){
    rep(j, n){
      if (grid[i][j] == 'o')continue;
      for (int k = j; k < n; k++){
        if(k + 1 < n && grid[i][k] == '.' && grid[i][k] == grid[i][k+1]){
          grid[i][k] = 'o';
          continue;
        }
        int s = k;
        if(i+ 1 < n  && grid[i][s] == '.' && grid[i][s] == grid[i+1][s]){
          grid[i][s] = 'o';
          for (int t = s; t< n; t++){
            if(t + 1 < n && grid[i+1][t] == '.'  && grid[i+1][t] == grid[i+1][t+1]){
              grid[i + 1][t] = 'o';
              continue;
            }
            grid[i + 1][t] = 'o';
            ans++;
            break;
          }
        }else if(grid[i][s] == '.'){
          grid[i][s] = 'o';
          ans++;
          continue;
        }
      }
    }
  }
  cout << ans << endl;
}