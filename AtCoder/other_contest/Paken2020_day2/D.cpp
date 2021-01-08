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
      if(ind[e] == 0)que.push(e);
    }
  }
  return ans;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> ai(n);
  vector<vector<int>> bi(n);
  int mx = 0;
  rep(i, n){
    int sz;
    cin >> sz;
    ai[i].resize(sz);
    rep(j, sz){
      int d;
      cin >> d;
      chmax(mx, d);
      d--;
      ai[i][j] = d;
    }
    cin >> sz;
    bi[i].resize(sz);
    rep(j, sz){
      int d;
      cin >> d;
      chmax(mx, d);
      d--;
      bi[i][j] = d;
    }
  }
  Graph G(n + mx);
  rep(i, n){
    rep(j, ai[i].size()){
      G[i].emplace_back(ai[i][j] + n);
    }
    rep(j, bi[i].size()){
      G[bi[i][j] + n].emplace_back(i);
    }
  }
  vector<int> ans = topo_sort(G);
  reverse(ALL(ans));
  int cn = 0;
  if(ans.size() == G.size()){
    rep(i, G.size()){
      if(ans[i] < n){ 
        cn++;
        cout << ans[i] + 1 << (cn == n ? "\n" : " ");
      }
    }
  }else{
    cout << -1 << endl;
  }
}