#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);
int n, k;
vector<string> grid(8);
int ans = 0;

void dfs(vector<string> gr){
  int cn = 0;
  rep(i, n) rep(j, n) if (gr[i][j] == '@') cn++;
  if(cn == k){
    ans++;
    return;
  }
  rep(i, n)rep(j, n){
    if(gr[i][j] != '.')continue;
    if(cn > 0){
      bool ok = false;
      rep(s, 4){
        int nx = i + dx[s], ny = j + dy[s];
        if(nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
        if(gr[nx][ny] == '#')continue;
        if(gr[nx][ny] == '.')continue;
        ok = true;
      }
      if(!ok)continue;
    }
    gr[i][j] = '@';
    dfs(gr);
    gr[i][j] = '#';
    dfs(gr);
    return;
  }
}

int main() {
  cin >> n >> k;
  rep(i, n) cin >> grid[i];
  //rep(i, n)rep(j, n){
  //  if(grid[i][j] == '#')continue;
  //  //vector<vector<int>> visit(n, vector<int>(n, 0));
  //  grid[i][j] = '@';
  //  dfs(grid);
  //  grid[i][j] = '.';
  //}
  dfs(grid);
  cout << ans << endl;
}