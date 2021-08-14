#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> dist(n + m, -2);
  G.resize(n + m);
  dist[0] = 0;
  rep(i, m){
    int k;
    cin >> k;
    rep(j, k){
      int d;
      cin >> d;
      d--;
      G[n + i].pb(d);
      G[d].pb(n + i);
    }
  }
  queue<int> que;
  que.push(0);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for(int u: G[v]){
      if(dist[u] != -2) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
  rep(i, n){
    cout << dist[i] / 2 << endl;
  }
}