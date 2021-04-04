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
const ll INF = (1LL < 60);

void solve() {
  int n;
  cin >> n;
  vector<ll> A(3), B(3);
  rep(i, 3) cin >> A[i];
  rep(i, 3) cin >> B[i];
  ll mx = min(A[1], B[2]) + min(A[2], B[0]) + min(A[0], B[1]);
  ll mn = -INF;
  chmax(mn, B[0] - A[0] - A[1]);
  chmax(mn, B[1] - A[1] - A[2]);
  chmax(mn, B[2] - A[2] - A[0]);
  if(mn <= 0)mn = 0;
  cout << mn << " " << mx << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}