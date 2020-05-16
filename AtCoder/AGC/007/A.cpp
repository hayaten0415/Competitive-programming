#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};
vector<string> grid;
int h, w;

void dfs(int y, int x, vector<vector<bool>> &visited){
  visited[y][x] = true;
  vector<bool> cond(2,false);
  for (int i = 0; i < 2; i++){
    int ny = y + dy[i], nx = x + dx[i];
    if(ny < 0 || h <= ny || nx < 0 || w <= nx || grid[ny][nx] == '.'){
      continue;
    }else {
      cond[i] = true;
    }
  } 
  if(cond[0] ^ cond[1]){
    if(cond[0] == 1){
      dfs(y + dy[0], x + dx[0], visited);
    }else{
      dfs(y + dy[1], x + dx[1], visited);
    }
  }else {
    return;
  }
}

int main() {
  cin >> h >> w;
  grid.resize(h);
  vector<vector<bool>> visited(h, vector<bool>(w, false));
  rep(i, h) cin >> grid[i];
  dfs(0, 0, visited);
  rep(i,h){
    rep(j,w){
      if(grid[i][j] == '#' && !visited[i][j]){
        cout << "Impossible" << endl;
        return 0;
      }
    }
  }
  cout << "Possible" << endl;
}