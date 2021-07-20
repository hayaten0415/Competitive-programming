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
  int n, k;
  cin >> n >> k;
  vector<int> A(k);
  vector<ll> T(k);
  rep(i, k){
    cin >> A[i];
    A[i]--;
  }
  vector<ll> cost(n, INT_MAX);
  vector<ll> L(n, INT_MAX);
  vector<ll> R(n, INT_MAX);
  rep(i, k) cin >> T[i];
  rep(i, k){
    cost[A[i]] = T[i];
  }
  ll p = INT_MAX;
  rep(i, n){
    p = min(p + 1, cost[i]);
    L[i] = p;
  }
  p = INT_MAX;
  rrep(i, n){
    p = min(p + 1, cost[i]);
    R[i] = p;
  }
  rep(i, n){
    cout << min(L[i], R[i]) << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}