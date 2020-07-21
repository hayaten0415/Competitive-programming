#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
vector<P> ans1;
vector<P> ans2;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};


//void dfs(int y, int x, vector<vector<bool>> &visited,  vector<vector<int>> &grid){
//  visited[y][x] = true;
//  if(grid[y][x] % 2 == 0){
//    dfs()
//  }
//  vector<int> cond;
//  for (int i = 0; i < 5; i++){
//    int ny = y + dy[i], nx = x + dx[i];
//    if(ny < 0 || h <= ny || nx < 0 || w <= nx){
//      continue;
//    }
//  }
//}

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> grid(h, vector<int>(w));
  vector<P> ans1;
  vector<P> ans2;
  rep(i, h){
    rep(j, w){
      cin >> grid[i][j];
    }
  }
  rep(i, h){
    rep(j, w){
      if(grid[i][j] % 2 == 0)continue;
      vector<bool> cond; 
      rep(k, 2){
        int ny = i + dy[k];
        int nx = j + dx[k];
        if(ny < 0 || h <= ny || nx < 0 || w <= nx)continue;
        if(grid[ny][nx] % 2 == 1){
          ans1.push_back({i + 1, j + 1});
          ans2.push_back({ny + 1, nx + 1});
          grid[i][j]--;
          grid[ny][nx]++;
          cond.push_back(false);
          break;
        }
      }
      if(cond.size() == 0){
        if(j == w-1 & i != h-1){
          grid[i][j]--;
          grid[i + 1][j]++;
          ans1.push_back({i + 1, j + 1});
          ans2.push_back({i + 2, j + 1});
        }else if (j != w-1){
          grid[i][j]--;
          grid[i][j+1]++;
          ans1.push_back({i + 1, j + 1});
          ans2.push_back({i + 1, j + 2});
        }
      }
    }
  }
  cout << ans1.size() << endl;
  rep(i, ans1.size()){
    cout << ans1[i].first << " " << ans1[i].second << " " << ans2[i].first << " " << ans2[i].second << endl;
  }
}