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
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
using Graph = vector<vector<int>>;
int dep[200002];
int in[200002];
int out[200002];
int k;
Graph G(200002);
vector<int> ls[200002];

void dfs(int v, int d) {
  in[v] = k; k++;
  dep[v] = d;
  for (int u : G[v]) dfs(u, d+1);
  out[v] = k;
}

  
int main() {
  int n;
  cin >> n;
  rep(i, n-1){
    int p;
    cin >> p;
    G[p - 1].pb(i + 1);
  }
  dfs(0, 0);
  rep(i, n) ls[dep[i]].push_back(in[i]);
  rep(i, n) sort(ls[i].begin(), ls[i].end());
  int q;
  cin >> q;
  auto f = [&](int d, int r) {
    return int(lower_bound(ls[d].begin(), ls[d].end(), r) - ls[d].begin());
  };
  rep(qi,q) {
    int u, d;
    cin >> u >> d;
    --u;
    int ans = f(d, out[u]) - f(d, in[u]);
    cout << ans << endl;
  }
}