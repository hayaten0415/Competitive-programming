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
#define rep(i, n) for (int i = 0; i < (n); i++)
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
  vector<int> cn(n), cn2(n);
  vector<vector<int>> sale(n);
  rep(i, n) cin >> cn[i];
  int sum = accumulate(ALL(cn), 0);
  set<P> st1;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    b--;
    st1.insert({b, a});
  }
  for(auto [a, b]: st1){
    sale[a].eb(b);
  }
  int ng = sum - 1, ok = sum * 2;
  auto f = [&](int x)-> bool{
    vector<P> res;
    rep(i, n){
      int c = upper_bound(ALL(sale[i]), x) - sale[i].begin();
      if(c == 0)continue;
      c--;
      res.pb({sale[i][c], i});
    }
    vector<int> cn2 = cn;
    sort(ALL(res));
    int num = 0;
    int cost = 0;
    for(auto [a, b]: res){
      int d = min(max(a - cost, 0), cn2[b]);
      cn2[b] -= d;
      cost += d;
    }
    rep(i, n) num += cn2[i];
    return num * 2 + cost <= x;
  };
  while(ok - ng > 1){
    int mid = (ng + ok) / 2;
    if(f(mid)){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  cout << ok << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}