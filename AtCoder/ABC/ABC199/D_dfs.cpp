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
vector<int> color, used;
vector<int> vs;
ll now = 0;

void dfs(int v){
  if(used[v])return;
  used[v] = 1;
  vs.push_back(v);
  for(auto u : G[v])dfs(u);
}

void dfs2(int i){
  if(i == vs.size()){
    now++;
    return;
  }
  int v = vs[i];
  rep(j, 3){
    color[v] = j;
    bool ok = true;
    for(int u : G[v]){
      if(color[u] == j)ok = false;
    }
    if(!ok)continue;
    dfs2(i + 1);
  }
  color[v] = -1;
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
    G[b].pb(a);
  }
  ll ans = 1;
  color = vector<int>(n, -1);
  used = vector<int>(n);
  rep(i, n){
    if(used[i])continue;
    ans *= 3;
    vs = vector<int>();
    dfs(i);
    color[vs[0]] = 0;
    now = 0;
    dfs2(1);
    ans *= now;
  }
  cout << ans << endl;
}