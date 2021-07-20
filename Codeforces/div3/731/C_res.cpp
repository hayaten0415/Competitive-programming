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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  int a = 0, b = 0;
  vector<int> ans;
  bool ok = true;
  while(a < n || b < m){
    if(a < n && A[a] == 0){
      ans.pb(0);
      a++;
      k++;
    }else if(b < m && B[b] == 0){
      ans.pb(0);
      b++;
      k++;
    }else if(a < n && A[a] <= k){
      ans.pb(A[a]);
      a++;
    }else if(b < m && B[b] <= k){
      ans.pb(B[b]);
      b++;
    }else{
      cout << -1 << endl;
      ok = false;
      break;
    }
  }
  if(ok){
    rep(i, n+m){
      cout << ans[i] << (i == n + m - 1 ? "\n" : " ");
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}