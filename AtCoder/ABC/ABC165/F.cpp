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
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 50);
vector<int> ans;
Graph G;
vector<ll> A;
vector<ll> dp;

//int LIS(vector<ll> &A){
//  int n = A.size();
//  vector<ll> dp(n, INF);
//  rep(i, n){
//    auto it = lower_bound(ALL(dp), A[i]);
//    *it = A[i];
//  }
//  return lower_bound(ALL(dp), INF) - dp.begin();
//}

void dfs(int u, int pre){
  int ind = lower_bound(ALL(dp), A[u]) - dp.begin();
  ll tmp = dp[ind];
  dp[ind] = A[u];
  ans[u] = lower_bound(ALL(dp), INF) - dp.begin();
  for(auto v : G[u]){
    if(v == pre)continue;
    dfs(v, u);
  }
  dp[ind] = tmp;
}

int main() {
  int n;
  cin >> n;
  A.resize(n);
  rep(i, n) cin >> A[i];
  G.resize(n);
  ans.resize(n);
  dp = vector<ll>(n, INF);
  rep(i, n-1){
    int u, v;
    cin >> u >> v;
    u--, v--;
    G[u].eb(v);
    G[v].eb(u);
  }
  dfs(0, -1);
  rep(i, n){
    cout << ans[i] << endl;
  }
}