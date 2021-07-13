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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PP = pair<P, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);
ll op(ll a, ll b) { return min(a, b); }
ll e() { return INF; }


int main() {
  int n, l;
  cin >> n >> l;
  vector<PP> cost(n);
  rep(i, n) cin >> cost[i].first.second >> cost[i].first.first >> cost[i].second;
  sort(ALL(cost));
  vector<ll> dp(l + 1, INF);
  dp[0] = 0;
  segtree<ll, op, e> seg(dp);
  rep(i, n){
    ll d = seg.prod(cost[i].first.second, cost[i].first.first + 1);
    ll tmp = seg.get(cost[i].first.first);
    chmin(tmp, d + cost[i].second);
    seg.set(cost[i].first.first, tmp);
  }
  cout << seg.get(l) << endl;
}