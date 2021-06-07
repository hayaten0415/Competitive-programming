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
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
Graph G;
bool ok[2000][2000];

void dfs(int u, int pre, int s){
  ok[s][u] = true;
  for(auto v : G[u]){
    if(ok[s][v])continue;
    if(v == pre)continue;
    dfs(v, u, s);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
  }
  rep(i, n){
    dfs(i, -1, i);
  }
  int ans = 0;
  rep(i, n) for (int j = 0; j < n; j++){
    if(ok[i][j])ans++;
  }
  cout << ans << endl;
}