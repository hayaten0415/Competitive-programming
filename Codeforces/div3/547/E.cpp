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
  ll h;
  ll n;
  cin >> h >> n;
  vector<ll> d(n);
  rep(i, n) cin >> d[i];
  ll rest2 = h;
  deque<ll> deq;
  ll mn = INF<ll>;
  int ind = -1;
  ll num = 0;
  bool o = false;
  rep(i, n){
    rest2 += d[i];
    if(rest2 <= 0){
      cout << i + 1 << endl;
      return;
    }
    num += d[i];
    chmin(mn, num);
    deq.pb(mn);
  }
  if(rest2 > 0 & num >= 0){
    cout << -1 << endl;
    return;
  }
  ll h2 = h;
  h2 += mn;
  ll ans =  (h2+abs(num) -1) / abs(num);
  ll ng = -1, ok = ans;
  auto f = [&](ll x){
    ll rest = h;
    rest += x * num;
    rest += mn;
    return rest;
  };
  while(ok - ng > 1){
    ll mid = (ok + ng) / 2;
    if(f(mid) <= 0){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  for (ll i = max(ok * n - n, 1LL); i <= ok * n + n; i++){
    ll rest = h;
    ll d = i / n;
    ll c = i % n;
    rest += d * num;
    if(c > 0)rest += deq[c-1];
    if(rest <= 0){
      cout << i << endl;
      return;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}