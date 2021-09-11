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
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<deque<int>> left(27), right(27);
  vector<P> ans;
  rep(i, n){
    if(s[i] == '?'){
      left[26].pb(i + 1);
      continue;
    }
    int a = s[i] - 'a';
    left[a].pb(i + 1);
  }
  rep(i, n){
    if(t[i] == '?'){
      right[26].pb(i + 1);
      continue;
    }
    int a = t[i] - 'a';
    right[a].pb(i + 1);
  }
  rep(i, 26){
    if(left[i].size() == 0)continue;
    while(!right[i].empty() & !left[i].empty()){
      int a = left[i].front();
      int b = right[i].front();
      ans.pb({a, b});
      left[i].pop_front();
      right[i].pop_front();
    }
  }
  rep(i, 27){
    while(!right[i].empty() & !left[26].empty()){
      int a = left[26].front();
      int b = right[i].front();
      ans.pb({a, b});
      left[26].pop_front();
      right[i].pop_front();
    }
  }
  rep(i, 27){
    while(!right[26].empty() & !left[i].empty()){
      int a = left[i].front();
      int b = right[26].front();
      ans.pb({a, b});
      left[i].pop_front();
      right[26].pop_front();
    }
  }
  cout << ans.size() << endl;
  for(auto [a, b] : ans){
    cout << a << " " << b << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}