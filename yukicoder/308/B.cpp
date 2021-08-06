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

Graph G;
vector<ll> ans(1e5, 0);
vector<int> depth(1e5);

void dfs(int u, int p){
  if(p != -1) ans[u] += ans[p];
  for(auto v: G[u]){
    if(v == p) continue;
    dfs(v, u);
  }
}

int dfs2(int u, int p){
  depth[u] = 1;
  for(auto v: G[u]){
    if(v == p) continue;
    depth[u] += dfs2(v, u);
  }
  return depth[u];
}

int main() {
  int n, q;
  cin >> n >> q;
  G.resize(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  vector<PL> res;
  vector<ll> re(q);
  rep(i,q) {
    int p;
    ll x;
    cin >> p >> x;
    p--;
    ans[p] += x;
    res.push_back({p, x});
  }
  dfs(0, -1);
  dfs2(0, -1);
  ll sum = accumulate(ans.begin(), ans.end(), 0LL);
  rrep(i, q){
    //cout << sum << endl;
    re[i] = sum;
    sum -= res[i].second * depth[res[i].first];
  }
  rep(i, q){
    cout << re[i] << endl;
  }
}