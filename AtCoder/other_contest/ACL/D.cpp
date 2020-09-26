#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  rep(i, n){
    cin >> grid[i];  
  }
  mf_graph<ll> g(n * m + 2);
  int s = n * m, t = n * m + 1;
  rep(i, n){
    rep(j, m){
      if(grid[i][j] == '#')continue;
      if((i + j) % 2 == 0)g.add_edge(s, i * m + j, 1);
      else g.add_edge(i * m + j, t, 1);
    }
  }
  rep(i, n){
    rep(j, m){
      if(grid[i][j] == '#')continue;
      if((i+j)%2 != 0) continue;
      rep(k, 4){
        int nx = j + dx[k];
        int ny = i + dy[k];
        if(nx < 0 || ny < 0 || nx >= m || ny >= n)continue;
        g.add_edge(i * m + j, ny * m + nx, 1);
      }
    }
  }
  cout << g.flow(s, t) << endl;
  auto edges = g.edges();
  for(auto e : edges){
    if(e.from == s || e.to == t || e.flow == 0)continue;
    int i0 = e.from / m, j0 = e.from % m;
    int i1 = e.to / m, j1 = e.to % m;
    if(i0 + 1 == i1){
      grid[i0][j0] = 'v';
      grid[i1][j1] = '^';
    }else if(i0 == i1 + 1){
      grid[i0][j0] = '^';
      grid[i1][j1] = 'v';
    }else if(j0 == j1 + 1){
      grid[i1][j1] = '>'; grid[i0][j0] = '<';
    }else{
      grid[i0][j0] = '>'; grid[i1][j1] = '<';
    }
  }
  rep(i, n){
    cout << grid[i] << endl;
  }
}