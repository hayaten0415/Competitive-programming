#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using PP = pair<int, long long>;
using Graph = vector<vector<PP>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 60);
Graph G;
int n, m;

void bfs(){
  queue<PP> que;
  vector<ll> dist(n, INF);
  rep(i, n){
    if(dist[i] != INF)continue;
    que.push(PP(i, 0));
    dist[i] = 0;
    while (!que.empty()){
      auto v = que.front();
      que.pop();
      int p = v.first;
      for(auto d : G[p]){
        int np = d.first;
        ll ndist = dist[p] + d.second;
        if(dist[np] == INF){
          dist[np] = ndist;
          que.push(d);
        }else{
          if(dist[np] != ndist){
            cout << "No" << endl;
            return;
          }
        }
      }
    }
  }
  cout << "Yes" << endl;
}

int main() {
  cin >> n >> m;
  G.resize(n);
  rep(i, m){
    int from, to;
    ll cost;
    cin >> from >> to >> cost;
    from--, to--;
    G[from].emplace_back(PP(to, cost));
    G[to].emplace_back(PP(from, -cost));
  }
  bfs();
}