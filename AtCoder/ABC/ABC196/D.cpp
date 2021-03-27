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
bool used[16][16];


ll dfs(int i, int j, int a, int b){
  if(a < 0 || b < 0)return 0;
  if(j == w)j = 0, ++i;
  if(i == h)return 1;
  if(used[i][j])return dfs(i, j + 1, a, b);
  ll res = 0;
  used[i][j] = true;
  res += dfs(i, j + 1, a, b - 1);
  if(j + 1 < w && !used[i][j+1]){
    used[i][j + 1] = true;
    res += dfs(i, j + 1, a - 1, b);
    used[i][j + 1] = false;
  }
  if(i + 1 < h && !used[i+1][j]){
    used[i+1][j] = true;
    res += dfs(i, j + 1, a - 1, b);
    used[i+1][j] = false;
  }
  used[i][j] = false;
  return res;
}

int main() {
  int a, b;
  cin >> h >> w >> a >> b;
  cout << dfs(0, 0, a, b) << endl;
}