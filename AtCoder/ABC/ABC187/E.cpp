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

using Graph = vector<vector<int>>;
Graph G;
vector<int> depth;
vector<ll> ans;


void dfs(int a, ll now){
  now += ans[a];
  ans[a] = now;
  for(auto v: G[a]){
    if(depth[v] > depth[a]){
      dfs(v, now);
    }
  }
}

int main() {
  int n, q;
  cin >> n;
  G.resize(n);
  depth.resize(n, -1);
  ans.resize(n, 0);
  vector<P> edge(n - 1);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    edge[i] = {a, b};
    G[a].push_back(b);
    G[b].push_back(a);
  }
  queue<int> que;
  que.push(0);
  depth[0] = 0;
  while (!que.empty()){
    int a = que.front();
    que.pop();
    for(auto v : G[a]){
      if(depth[v] != -1)continue;
      depth[v] = depth[a] + 1;
      que.push(v);
    }
  }
  cin >> q;
  rep(i,q) {
    int t, e;
    ll x;
    cin >> t >> e >> x;
    e--;
    int na, nb;
    if(t == 1){
      na = edge[e].first;
      nb = edge[e].second;
    }else{
      nb = edge[e].first;
      na = edge[e].second;
    }
    if(depth[na] < depth[nb]){
      ans[0] += x;
      ans[nb] -= x;
    }else{
      ans[na] += x;
    }
  }
  dfs(0, 0LL);
  rep(i,n){
    cout << ans[i] << "\n";
  }
}