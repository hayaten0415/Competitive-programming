#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 50);
ll dp[405][405];
bool used[405][405];
ll A[405];

ll rec(int l, int r) {
  if ((r - l) <= 1) return INF;
  if ((r - l) == 2) return dp[l][r] = abs(A[l] - A[l+1]);
  if (used[l][r]) return dp[l][r];
  ll ret = INF;
  chmin(ret, rec(l + 1, r - 1) + abs(A[l] - A[r - 1]));
  for (int i = l + 1; i < r; i++) {
    chmin(ret, rec(l, i) + rec(i, r));
  }
  used[l][r] = true;
  return dp[l][r] = ret;
}

int main() {
  int n;
  cin >> n;
  n *= 2;
  rep(i, n) cin >> A[i];
  rep(i, 405) rep(j, 405) dp[i][j] = INF;
  cout << rec(0, n) << endl;
}