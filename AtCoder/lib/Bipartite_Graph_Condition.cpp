#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
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
vector<int> color(100007, 0);

bool dfs(int u, int c){
  color[u] = c;
  for(auto v : G[u]){
    if(color[v] == color[u])return false;
    if(color[v] == 0 && !dfs(v,-c)) return false;
  }
  return true;
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
  //グラフが連結でないことを想定し各頂点に対してDFSを行う
  rep(i, n){
    if(color[i] == 0){
      if(!dfs(i, 1)){
        //二部グラフではない
        cout << "No" << endl;
        return 0;
      }
    }
  }
  //二部グラフである。
  cout << "Yes" << endl;
}