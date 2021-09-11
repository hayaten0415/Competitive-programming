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
  vector<int> q(n - 1);
  rep(i, n - 1) cin >> q[i];
  rep(i, n - 2) q[i + 1] += q[i];
  set<int> st;
  vector<int> ans(n);
  rep(i, n-1){
    st.insert(q[i]);
  }
  if(st.size() != n-1){
    cout << -1 << endl;
    return;
  }
  int mn = *st.begin();
  int mx = *st.rbegin();
  int num = -1;
  if(mn == -n + 1)num = n;
  if(mx == n -1)num = 1;
  if(n - mx == 1 - mn)num = 1 - mn;
  if(num == -1){
    cout << -1 << endl;
    return;
  }
  rep(i, n){
    if(i == 0)ans[i] = num;
    else ans[i]= num + q[i-1];
  }
  set<int> st2;
  rep(i, n){
    st2.insert(ans[i]);
  }
  int a = 1;
  for(int d : st2){
    if(a != d){
      cout << -1 << endl;
      return;
    }
    a++;
  }
  rep(i, n){
    cout << ans[i] << (i == n-1? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}