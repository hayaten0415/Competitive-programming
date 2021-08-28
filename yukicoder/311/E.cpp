#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;



vector<int> topo_sort(const Graph &G){
  int n = G.size();
  vector<int> ans;
  vector<int> ind(n);
  rep(i, n) for (auto v : G[i]) ind[v]++;
  queue<int> que;
  rep(i, n) if(ind[i] == 0)que.push(i);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    ans.emplace_back(v);
    for(auto e : G[v]){
      ind[e]--;
      if(ind[e] == 0)que.push(e);
    }
  }
  return ans;
}

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
  }
  vector<int> g = topo_sort(G);
  vector<int> dp(n, 0);
  if(g.size() == n){
    for(int a : g){
      for(int c : G[a]){
        chmax(dp[c], dp[a] + 1);
      }
    }
    cout << *max_element(ALL(dp)) + 1 << endl;
  }else{
    cout << -1 << endl;
  }
}