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
using PP = pair<int, P>;
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
  vector<int> cn(2e5 + 1);
  vector<int> A(n);
  rep(i, n){
    cin >> A[i];
    cn[A[i]]++;
  }
  int mx_num = 0;
  int mx = 0;
  rep(i, 2e5+1){
    if(chmax(mx, cn[i])){
      mx_num = i;
    }
  }
  queue<int> que;
  vector<bool> used(n, false);
  vector<PP> ans;
  rep(i, n){
    if(A[i] == mx_num)que.push(i);
  }
  while (!que.empty()){
    int a = que.front();
    que.pop();
    used[a] = true;
    if(a > 0){
      if(!used[a-1] & A[a-1] != mx_num){
        que.push(a-1);
        if(A[a] > A[a-1]){
          ans.pb({1, {a, a+1}});
        }else{
          ans.pb({2, {a , a+1}});
        }
        A[a - 1] = mx_num;
      }
    }
    if(a < n-1){
      if(!used[a+1] & A[a+1] != mx_num){
        que.push(a+1);
        if(A[a] > A[a+1]){
          ans.pb({1, {a + 2, a+1}});
        }else{
          ans.pb({2, {a + 2, a+1}});
        }
        A[a + 1] = mx_num;
      }
    }
  }
  cout << ans.size() << endl;
  for(auto [a, b] : ans){
    auto [c, d] = b;
    cout << a << " " << c << " " << d << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}