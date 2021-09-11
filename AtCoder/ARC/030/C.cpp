#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
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

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<char> C(n);
  vector<int> A(m), B(m);
  rep(i, n) cin >> C[i];
  scc_graph g(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    A[i] = a;
    B[i] = b;
    g.add_edge(a, b);
  }
  auto scc = g.scc();
  int sz = scc.size();
  vector<int> id(n);
  rep(i, sz) {
    for(int v : scc[i]) {
      id[v] = i;
    }
  }
  Graph G(sz);
  rep(i, m) {
    if(id[A[i]] != id[B[i]]) {
        G[id[A[i]]].pb(id[B[i]]);
    }
  }
  string inf = "";
  rep(i, k+1) {
    inf += '~';
  }
  vector<vector<string>> dp(sz, vector<string>(k + 1, inf));
  rep(i, sz) {
    dp[i][0] = "";
  }
  string ans = inf;
  rep(i, sz){
    for (int j = 0; j <= k; j++){
      if(dp[i][j] == inf)continue;
      string s = dp[i][j];
      string t = ""; // 強連結成分iで可能な辞書順最小
      for(int v : scc[i]) {
        t += C[v];
      }
      sort(ALL(t));
      for(auto d : G[i]){
        chmin(dp[d][j], s);
      }
      rep(y, (int)t.size()) {
        s += t[y];
        if((int)s.size() == k) {
            chmin(ans, s);
            break;
        }
        for(int d : G[i]) {
            chmin(dp[d][(int)s.size()], s);
        }
      }
    }
  }
  if(ans == inf)ans = "-1";
  cout << ans << endl;
}