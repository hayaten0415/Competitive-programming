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
vector<int> dist;
vector<int> topo_sort(const Graph &G){
  int n = G.size();
  vector<int> ans;
  vector<int> ind(n);
  rep(i, n) for (auto v : G[i]) ind[v]++;
  queue<int> que;
  rep(i, n) if(ind[i] == 0)que.push(i);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    ans.emplace_back(v);
    for(auto e : G[v]){
      ind[e]--;
      chmax(dist[e], dist[v] + 1);
      if(ind[e] == 0)que.push(e);
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  dist.resize(n);
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
  }
  vector<int> ans = topo_sort(G);
  vector<int> cn(n);
  bool one = true;
  rep(i, n){
    cn[dist[i]]++;
    if(cn[dist[i]] > 1)one = false;
  }
  rep(i, n){
    cout << ans[i] + 1 << endl;
  }
  if(one){
    cout << 0 << endl;
  }else{
    cout << 1 << endl;
  }
}