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
  ll a, b, c;
  cin >> a >> b >> c;
  ll mn_week = INF<ll>;
  chmin(mn_week, (a / 3));
  chmin(mn_week, (b / 2));
  chmin(mn_week, (c / 2));
  a -= mn_week * 3;
  b -= mn_week * 2;
  c -= mn_week * 2;
  ll ans = mn_week * 7;
  vector<ll> rest = {a, b, c};
  vector<int> tmp = {0, 1, 2, 0, 2, 1, 0, 0, 1, 2, 0, 2, 1, 0};
  ll mx = 0;
  deque<int> deq;
  rep(i, 14){
    deq.pb(tmp[i]);
    rest[tmp[i]]--;
    while(rest[0] < 0 || rest[1] < 0 || rest[2] < 0){
      int a = deq.front();
      deq.pop_front();
      rest[a]++;
    }
    chmax(mx, (ll)deq.size());
  }
  ans += mx;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}