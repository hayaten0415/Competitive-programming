#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<string> grid(10);

void dfs(int y, int x, vector<vector<bool>> &visited){
  visited[y][x] = true;
  for (int i = 0; i < 4; i++){
    int ny = y + dy[i], nx = x + dx[i];
    if(ny < 0 || 10 <= ny || nx < 0 || 10 <= nx) continue;
    if(visited[ny][nx]) continue;
    if(grid[ny][nx] == 'x') continue;
    dfs(ny, nx, visited);
  }
}

bool aval(int y, int x){
  vector<vector<bool>> visited(10, vector<bool>(10, false));
  dfs(y, x, visited);
  rep(i, 10){
    rep(j,10){
      if(grid[i][j] == 'o' && visited[i][j] == false){
        return false;
      }
    }
  }
  return true;
}

int main(){
  rep(i, 10) cin >> grid[i];
  bool cond = false;
  rep(i, 10){
    rep(j,10){
      if(aval(i,j)){
        cond = true;
      }
    }
  }
  cout << (cond ? "YES" : "NO") << endl;
}