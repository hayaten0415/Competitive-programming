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

int h, w;
bool stone[1502][1502];
bool dfs(int i, int j){
  bool ok = false;
  rep(v, 4){
    int nx = i + dy[v], ny = j + dx[v];
    if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
    if(stone[nx][ny])continue;
    ok = true;
  }
  return ok;
}



int main() {
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  rep(i, h){
    rep(j, w){
      if(grid[i][j] == '.')stone[i][j] = true;
    }
  }
  rep(i, h){
    rep(j, w){
      bool ok = true;
      if(grid[i][j] == '#')ok = dfs(i, j);
      if(!ok){
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
}