#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
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
const auto INF = numeric_limits<T>::max();


void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  vector<int> plat(m);
  vector<int> plat_index(m);
  rep(i, m) cin >> plat[i];
  vector<int> ans(n);
  int start = n;
  rrep(i, m){
    start -= (plat[i] - 1);
    start--;
    plat_index[i] = start;
  }
  start = -1 + d;
  rep(i, m){
    int b = lower_bound(ALL(plat_index), start) - plat_index.begin();
    if(i < b){
      start = plat_index[b - 1] + (plat[i] - 1);
      start += d;
    }else{
      plat_index[i] = start;
      start += (plat[i] - 1);
      start += d;
    }
  }
  rep(i, m){
    ans[plat_index[i]] += (i + 1);
    if(plat_index[i] + plat[i] < n){
      ans[plat_index[i] + plat[i]] -= (i + 1);
    }
  }
  rep(i, n-1){
    ans[i + 1] += ans[i];
  }
  if(n - plat_index[m-1] - plat[m-1] +1 <= d){
    cout << "YES" << endl;
    rep(i, n){
      cout << ans[i] << (i == n - 1 ? "\n" : " ");
    }
  }else{
    cout << "NO" << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}