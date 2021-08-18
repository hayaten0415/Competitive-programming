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
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, P>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/ 2;


void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<PL> edge(m);
  rep(i, m){
    cin >> edge[i].second.first >> edge[i].second.second >> edge[i].first;
    edge[i].second.first--;
    edge[i].second.second--;
  }
  sort(ALL(edge));
  vector<int> v;
  rep(i, min(m, k)){
    v.pb(edge[i].second.second);
    v.pb(edge[i].second.first);
  }
  sort(ALL(v));
  v.resize(unique(ALL(v)) - v.begin());
  int b = v.size();
  vector<vector<ll>> dist(b, vector<ll>(b, INF<ll>));
  rep(i, b) dist[i][i] = 0;
  rep(i, min(m, k)){
    int x = lower_bound(ALL(v), edge[i].second.first) - v.begin();
    int y = lower_bound(ALL(v), edge[i].second.second) - v.begin();
    chmin(dist[x][y], edge[i].first);
    chmin(dist[y][x], edge[i].first);
  }
  rep(i, b) rep(j, b) rep(k, b) chmin(dist[j][k], dist[j][i] + dist[i][k]);
  vector<ll> res;
  rep(i, b) for (int j = i + 1; j < b; j++) res.pb(dist[i][j]);
  sort(ALL(res));
  cout << res[k - 1] << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}