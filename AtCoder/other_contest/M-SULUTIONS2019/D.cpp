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
Graph G;
vector<int> ans;
vector<int> score;
vector<int> depth;

void dfs(int v, int u, int &d){
  if(ans[v]== -1){
    ans[v] = score[d];
  }
  for(auto f : G[v]){
    if(f == u)continue;
    if(ans[f] != -1)continue;
    d++;
    dfs(f, v, d);
  }
}

int main() {
  int n;
  cin >> n;
  G.resize(n);
  ans.assign(n, -1);
  score.resize(n);
  depth.resize(n, -1);
  vector<int> deg(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    deg[a]++;
    deg[b]++;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  rep(i, n) cin >> score[i];
  sort(ALL(score), greater{});
  queue<int> que;
  que.push(0);
  depth[0] = 0;
  ans[0] = score[0];
  int d = 1;
  while (!que.empty()){
    int a = que.front();
    que.pop();
    for(auto v : G[a]){
      if(depth[v] != -1)continue;
      depth[v] = depth[a] + 1;
      ans[v] = score[d];
      d++;
      que.push(v);
    }
  }
  int score_sum = 0;
  for (int i = 1; i < n; i++){
    score_sum += score[i];
  }
  cout << score_sum << endl;
  rep(i, n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}