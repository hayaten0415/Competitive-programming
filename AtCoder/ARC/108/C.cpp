#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
typedef long long ll;
using P = pair<int, int>;
using Edge = pair<int, int>; // {行き先, ラベル}
using Graph = vector<vector<Edge>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  vector<int> ans(n, -1);
  rep(i,m){
    int a, b, c;
    cin >> a >> b >> c;
    --a; --b;
    G[a].push_back(Edge(b, c));
    G[b].push_back(Edge(a,c));
  }
  queue<int> que;
  que.push(0);
  ans[0] = 1;
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for (auto p: G[v]){
      int w = p.first;
      int c = p.second;
      if(ans[w] == -1){
        if(c == ans[v]){
          if (c == 1){
            ans[w] = 2;
          } else {
            ans[w] = 1;
          }
        } else {
          ans[w] = c;
        }
        que.push(w);
      }
    }
  }
  rep(i, n){
    cout << ans[i] << endl;
  }
}