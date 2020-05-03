#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int H, W;
vector<string> grid;

bool visited[503][503];
void dfs(int h, int w){
  visited[h][w] = true;
  for (int i = 0; i < 4; i++){
    int nh = h + dx[i];
    int nw = w + dy[i];
    if(nh < 0 || nh >= H || nw < 0 || nw >= W) continue;
    if (grid[nh][nw] == '#')continue;
    if(visited[nh][nw]) continue;
    dfs(nh, nw);
  }
}


int main(){
  int sh, sw, gh, gw;
  cin >> H >> W;
  grid.resize(H);
  rep(i,H) cin >> grid[i];
  rep(i,H){
    rep(j,W){
      visited[i][j] = false;
      if(grid[i][j] == 's') sh = i, sw = j;
      if(grid[i][j] == 'g') gh = i, gw = j;
    }
  }
  dfs(sh, sw);
  cout << (visited[gh][gw] ? "Yes" : "No") << endl;
}