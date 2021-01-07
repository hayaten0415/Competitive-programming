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

struct Edge{
  int to;
};
using Graph = vector<vector<Edge>>;

vector<int> topo_sort(const Graph &G){
  int n = G.size();
  vector<int> ans;
  vector<int> ind(n);
  rep(i, n) for (auto v : G[i]) ind[v.to]++;
  queue<int> que;
  rep(i, n) if(ind[i] == 0)que.push(i);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    ans.emplace_back(v);
    for(auto e : G[v]){
      ind[e.to]--;
      if(ind[e.to] == 0)que.push(e.to);
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    Edge e;
    e.to = b;
    G[a].emplace_back(e);
  }
  vector<int> ans = topo_sort(G);
  if(ans.size() != n){
    cout << 1 << endl;
  }else{
    cout << 0 << endl;
  }
}