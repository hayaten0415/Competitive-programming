#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
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
const auto INF = numeric_limits<T>::max() / 2;

void solve() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].eb(b);
    G[b].eb(a);
  }
  vector<int> dist(n, INF<int>);
  queue<int> que;
  que.push(0);
  dist[0] = 0;
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for(int u: G[v]){
      if(dist[u] != INF<int>) continue;
      dist[u] = dist[v] + 1;
      que.push(u);
    }
  }
  vector<int> even, odd;
  rep(i, n){
    if(dist[i] % 2 == 0)even.eb(i);
    else odd.eb(i);
  }
  if(even.size() < odd.size()){
    cout << even.size() << endl;
    for(auto d :even){
      cout << d + 1 << " ";
    }
    cout << endl;
  }else{
    cout << odd.size() << endl;
    for(auto d :odd){
      cout << d + 1 << " ";
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}