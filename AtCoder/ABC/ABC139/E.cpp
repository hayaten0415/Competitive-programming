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
const int INF = (1 << 30);

struct Edge{
  int to;
};
using Graph = vector<vector<Edge>>;

vector<int> sum;
int change(int i, int j) {
    if (i < j) swap(i, j);
    return sum[j] + i - j;
}

int topo_sort(const Graph &G){
  int n = G.size();
  vector<int> ans;
  vector<int> dist(n);
  vector<int> ind(n);
  rep(i, n) for (auto v : G[i]) ind[v.to]++;
  queue<int> que;
  rep(i, n) if(ind[i] == 0){
    que.push(i);
  }
  while (!que.empty()){
    int v = que.front();
    que.pop();
    ans.emplace_back(v);
    for(auto e : G[v]){
      ind[e.to]--;
      chmax(dist[e.to], dist[v] +1);
      if(ind[e.to] == 0)que.push(e.to);
    }
  }
  if(ans.size() != n)return -1;
  return *max_element(ALL(dist));
}

int main() {
  int n;
  cin >> n;
  sum.resize(n-1);
  rep(i, n - 2) sum[i + 1] = sum[i] + n - 1 - i;
  Graph G((n * (n - 1)) / 2 + 1);
  rep(i, n){
    int now = 0;
    rep(j, n-1){
      int d;
      cin >> d;
      d--;
      int next = change(i, d);
      Edge e;
      e.to = next;
      G[now].emplace_back(e);
      now = next;
    }
  }
  cout << topo_sort(G) << endl;
}