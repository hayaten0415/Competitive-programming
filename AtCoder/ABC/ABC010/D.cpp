#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
const int INF = 10000000;

struct edge{
  //行き先、容量、逆辺
  int to, cap, rev;
  edge(int t, int c, int r){
    to = t; cap = c; rev = r;
  }
};

vector<edge> G[105];
bool used[105];

void add_edge(int from, int to, int cap){
  G[from].push_back((edge){to, cap, (int)G[to].size()});
  G[to].push_back((edge){from, 0, (int)G[from].size() -1});
}

int dfs(int v, int t, int f){
  if(v == t)return f;
  used[v] = true;

  rep(i,G[v].size()) {
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0) {
          int d = dfs(e.to,t,min(f,e.cap));
          if(d > 0) {
              e.cap -= d;
              G[e.to][e.rev].cap += d;
              return d;
          }
      }
  }
  return 0;
}

//sからtへの最大流を求める
int max_flow(int s,int t) {
  int flow = 0;
  for(;;) {
      memset(used,0,sizeof(used));
      int f = dfs(s,t,INF);
      if(f == 0) return flow;
      flow += f;
  }
}

int main() {
  int n, g, e;
  cin >> n >> g >> e;
  vector<int> woman(g);
  rep(i, g) cin >> woman[i];
  rep(i,e){
    int a, b;
    cin >> a >> b;
    add_edge(a, b, 1);
    add_edge(b, a, 1);
  }
  rep(i, g) {
    add_edge(woman[i], n+1, 1);
  }
  int s = 0, t = n + 1;
  cout << max_flow(s, t) << endl;
}