#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[9] = {1, 0, -1, 0, -1, 1, 1, -1, 0};
const int dy[9] = {0, 1, 0, -1, -1, 1, -1, 1, 0};
int n, m;
int ans[30][30];
string grid[30];

void dfs(int x, int y){
  rep(k, 9){
    int nx = x + dx[k], ny = y + dy[k];
    if(nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
    if(grid[nx][ny] == '.')continue;
    ans[x][y]++;
  }
}

int main() {
  cin >> n >> m;
  rep(i, n) cin >> grid[i];
  rep(i, n) rep(j, m) dfs(i, j);
  rep(i, n){
    rep(j, m){
      cout << ans[i][j];
    }
    cout << endl;
  }
}