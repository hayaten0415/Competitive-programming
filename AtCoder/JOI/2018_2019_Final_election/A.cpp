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
  int H, W;
  cin >> H >> W;
  vector<string> grid(H);
  rep(i, H) cin >> grid[i];
  vector<vector<ll>> O_sum(H, vector<ll>(W, 0));
  vector<vector<ll>> I_sum(H, vector<ll>(W, 0));
  rep(i, H){
    rep(j, W){
      if(grid[i][j] == 'O')O_sum[i][j]++;
      if(grid[i][j] == 'I')I_sum[i][j]++;
      if(j != 0)O_sum[i][j] += O_sum[i][j-1];
      if(i != 0)I_sum[i][j] += I_sum[i-1][j];
    }
  }
  ll ans = 0;
  rep(i, H){
    rep(j, W){
      if(grid[i][j] == 'J'){
        ans += (O_sum[i][W - 1] - O_sum[i][j]) * (I_sum[H - 1][j] - I_sum[i][j]);
      }
    }
  }
  cout << ans << endl;


}