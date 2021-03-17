#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int h, w;
string grid[100];
bool black[100][100];
bool ok[100][100];

bool black_condtion(int x, int y){
  if(grid[x][y] == '.')return false;
  rep(i, 8){
    int nx = x + fx[i], ny = y + fy[i];
    if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
    if(grid[nx][ny] == '.')return false;
  }
  return true;
}

bool cond(int x, int y){
  if(grid[x][y] == '.')return true;
  if(black[x][y])return true;
  rep(i, 8){
    int nx = x + fx[i], ny = y + fy[i];
    if(nx < 0 || ny < 0 || nx >= h || ny >= w)continue;
    if(grid[nx][ny] == '.')continue;
    if(black[nx][ny])return true;
  }
  return false;
}

int main() {
  cin >> h >> w;
  rep(i, h) cin >> grid[i];
  rep(i, h)rep(j, w) black[i][j] = black_condtion(i, j);
  rep(i, h) rep(j, w){
    ok[i][j] = cond(i, j);
    if(!ok[i][j]){
      cout << "impossible" << endl;
      return 0;
    }
  }
  cout << "possible" <<endl;
  rep(i, h){
    rep(j, w){
      if(black[i][j]) cout << "#";
      else cout << ".";
    }
    cout << endl;
  }
}