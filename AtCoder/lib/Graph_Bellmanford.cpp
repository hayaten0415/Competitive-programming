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
const ll INF = (1LL << 60);
int n, m;

struct Edge {
  int from, to;
  ll cost;
};

vector<Edge> v;
ll dist[2200];
bool negative[2200];

void bellman_ford(int start){
  rep(i, n) dist[i] = INF;
  dist[start] = 0;
  for (int i = 0; i < n-1; i++){
    for (int j = 0; j < v.size(); j++){
      Edge e = v[j];
      if(dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost){
        dist[e.to] = dist[e.from] + e.cost;
      }
    }
  }
  return;
}

void negative_loop(){
  rep(i, n) negative[i] = false;
  rep(i, n){
    for (int j = 0; j < v.size(); j++){
      Edge e = v[j];
      if(dist[e.to] != INF && dist[e.to] > dist[e.from] + e.cost){
        dist[e.to] = dist[e.from] + e.cost;
        negative[e.to] = true;
      }
      if(negative[e.from])negative[e.to] = true;
    }
  }
}

int main() {
  cin >> n >> m;
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    //有向グラフ想定
    v.push_back((Edge{a, b, -c}));
  }
  bellman_ford(0);
  ll ans = -dist[n-1];
  negative_loop();
  if(negative[n-1]){
    cout << "inf" << endl;
  }else{
    cout << ans << endl;
  }
}