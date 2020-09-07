#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
set<int> st;

void dfs(int c, int p, int k, Graph &G){
  if(k > 2)return;
  st.insert(c);
  for(auto e: G[c]){
    if(e == p)continue;
    dfs(e, c, k + 1, G);
  }
}


int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  dfs(0, -1, 0, G);
  cout << st.size() - 1 << endl;
}