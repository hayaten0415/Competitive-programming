#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
bool visited[100][100];
int h, w;
vector<string> grid(100);

int main() {
  cin >> h >> w;
  int x, y;
  cin >> x >> y;
  x--, y--;
  int ans = 0;
  rep(i, h) cin >> grid[i];
  for (int i = x; i < h; i++){
    if(grid[i][y] == '.')ans++;
    else break;
  }
  for (int i = x; i >= 0; i--){
    if(grid[i][y] == '.')ans++;
    else break;
  }
  for (int j = y; j >= 0; j--){
    if(grid[x][j] == '.')ans++;
    else break;
  }
  for (int j = y; j < w; j++){
    if(grid[x][j] == '.')ans++;
    else break;
  }
  cout << ans - 3 << endl;
}