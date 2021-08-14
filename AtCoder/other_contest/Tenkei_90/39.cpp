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
const int INF = (1 << 30);
Graph G;
ll dp[120000];

void dfs(int s, int pre){
  dp[s] = 1;
  for(auto v : G[s]){
    if(v == pre)continue;
    dfs(v, s);
    dp[s] += dp[v];
  }
}

int main() {
  int n;
  cin >> n;
  G.resize(n);
  vector<int> A(n-1), B(n-1);
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    A[i] = a;
    B[i] = b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0, -1);
  ll ans = 0;
  rep(i, n-1){
    ll d = min(dp[A[i]], dp[B[i]]);
    ans += d * (n - d);
  }
  cout << ans << endl;
}
