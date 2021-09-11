#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
  map<P, int> mp;
  map<P, int> mp2;
  vector<P> edge(m);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[i].fi = a;
    edge[i].se = b;
    G[a].pb(b);
    G[b].pb(a);
  }
  vector<int> color(n, -1);
  bool ok = true;
  auto dfs = [&](auto &&self, int v, int c)-> void{
    color[v] = c;
    for(auto to : G[v]){
      if(color[to] == -1){
        self(self, to, c ^ 1);
      }else{
        if(color[to] == color[v]){
          ok = false;
        }
      }
    }
  };
  dfs(dfs, 0, 0);
  if(!ok){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    rep(i, m){
      cout << (color[edge[i].fi] < color[edge[i].se]);
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}