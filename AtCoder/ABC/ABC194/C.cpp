#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), sum(n + 1), A_powsum(n + 1);
  rep(i, n) cin >> A[i];
  rep(i, n){
    sum[i + 1] = sum[i] + A[i];
    A_powsum[i + 1] = A_powsum[i] + (A[i] * A[i]);
  }
  ll ans = 0;
  rep(i, n-1){
    ans += (n - 1 - i) * A[i] * A[i];
    ans += -2 * (sum[n] - sum[i + 1]) * A[i];
    ans += A_powsum[n] - A_powsum[i + 1];
  }
  cout << ans << endl;
}