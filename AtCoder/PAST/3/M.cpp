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
const int INF = (1 << 30);
int dist[17][17];
Graph G;
vector<int> town;

void bfs(int s, int n){
  vector<int> dists(n, INF);
  queue<int> que;
  que.push(s);
  dists[s] = 0;
  while (!que.empty()){
    int u = que.front();
    que.pop();
    for(auto v : G[u]){
      if(dists[v] != INF)continue;
      dists[v] = dists[u] + 1;
      if(town[v] != -1){
        dist[town[s]][town[v]] = dists[v];
      }
      que.push(v);
    }
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  town.resize(n, -1);
  G.resize(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    if(a== b)continue;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  int s, k;
  cin >> s >> k;
  s--;
  vector<int> t(k+1);
  t[k] = s;
  town[s] = k;
  rep(i, k){
    cin >> t[i];
    t[i]--;
    town[t[i]] = i;
  }
  k++;
  rep(i, k){
    bfs(t[i], n);
  }
  int n2 = (1 << k);
  vector<vector<int>> dp(n2, vector<int>(k, INF));
  dp[1 << (k - 1)][k - 1] = 0;
  rep(i, n2){
    rep(j, k){
      if(!(i >> j & 1))continue;
      rep(s, k){
        if(i >> s & 1)continue;
        chmin(dp[i | 1 << s][s], dp[i][j] + dist[j][s]);
      }
    }
  }
  int ans = INF;
  rep(i, k){
    chmin(ans, dp[n2 - 1][i]);
  }
  cout << ans << endl;
}