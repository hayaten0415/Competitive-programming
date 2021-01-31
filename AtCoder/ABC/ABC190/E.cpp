#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = (1 << 30);
set<int> st2;
set<int> st;
int dist[17][17];
map<int, int> mp;
Graph G;

template <typename T>
map<T, int> compress(vector<T> &X) {
  vector<T> vals = X;
  int n = vals.size();
  map<T, int> mp;
  int cn = 0;
  rep(i, n){
    mp[X[i]] = 0;
  }
  for (auto &p : mp){
    p.second = cn;
    cn++;
  }
  return mp;
}
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
      if(st2.find(v) != st2.end()){
        dist[mp[s]][mp[v]] = dists[v];
      }
      que.push(v);
    }
  }
  return;
}

int main() {
  int n, m;
  cin >> n >> m;
  G.resize(n);
  dsu d(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    d.merge(a, b);
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  int k;
  cin >> k;
  vector<int> C(k);
  bool ok = true;
  rep(i, k){
    cin >> C[i];
    C[i]--;
    st2.insert(C[i]);
  }
  rep(i, k){
    st.insert(d.leader(C[i]));
  }
  if(st.size() != 1){
    cout << -1 << endl;
    return 0;
  }
  mp = compress(C);
  rep(i, k){
    dist[mp[C[i]]][mp[C[i]]] = 0;
    bfs(C[i], n);
  }
  int n2 = (1 << k);
  vector<vector<int>> dp(n2, vector<int>(k, INF));
  rep(i, k){
    dp[1 << i][i] = 1;
  }
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