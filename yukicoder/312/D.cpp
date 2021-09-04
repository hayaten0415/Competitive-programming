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
#define UNIQUE(v) v.erase(unique(ALL(v)), v.end())
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
const auto INF = numeric_limits<T>::max() / 8;




int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<ll> v;
  for (ll i = 3; i <= 60; i++) {
    ll j = 2;
    while (1) {
      __int128 p = 1;
      bool valid = true;
      rep(jj, i) {
        p *= j;
        if (p > ll(2e18)) {
          valid = false;
          break;
        }
      }
      if (not valid) break;
      ll d = sqrtl(p);
      if(d * d != p)v.push_back(ll(p));
      j++;
    }
  }
  sort(ALL(v));
  UNIQUE(v);
  auto f = [&](ll k) {
    ll lo = 0, hi = INF<ll>;
    while (hi - lo > 1) {
      ll mi = (lo + hi) / 2;
      ll c = upper_bound(ALL(v), mi) - v.begin();
      c += sqrtl(mi);
      if (c >= k)
        hi = mi;
      else
        lo = mi;
    }
    return hi;
  };
  int t;
  cin >> t;
  while(t--){
    ll k;
    cin >> k;
    cout << f(k) << endl;
  }
}