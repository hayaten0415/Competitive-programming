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

ll dp[1000][1000];
bool visited[400][400];
string grid[400];
int h, w;
ll res = 0;
vector<vector<ll>> black(160000);

void dfs(int x, int y, int sx, int sy){
  visited[x][y] = true;
	if(grid[x][y] == '.')res++;
  else black[w * x + y].push_back(w * sx + sy);
  rep(i, 4){
    int nx = x + dx[i], ny = y + dy[i];
    if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
    if(visited[nx][ny])continue;
    if(grid[x][y] != grid[nx][ny]){
			dfs(nx, ny, sx, sy);
		}
	}
  return;
}
int main() {
  cin >> h >> w;
  rep(i, h) cin >> grid[i];
  ll ans = 0;
	rep(i, h) rep(j, w){
    if(grid[i][j] == '.')continue;
    if(visited[i][j]){
      int x = black[i * w + j][0] / w;
      int y = black[i * w + j][0] % w;
      ans += dp[x][y];
    }else{
      res = 0;
      dfs(i, j, i, j);
      dp[i][j] = res;
      ans += res;
    }
  }
	cout << ans << endl;
}