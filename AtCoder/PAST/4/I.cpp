#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  vector<ll> A(n);
  vector<ll> sum(n + 1);
  rep(i, n) cin >> A[i];
  rep(i, n) sum[i + 1] = sum[i] + A[i];
  int right = 0;
  ll ans = (1LL << 60);
  for (int left = 0; left < n; ++left) {
    ll d = sum[right] - sum[left];
      while (right < n && abs((sum[n] - (sum[right] - sum[left])) - (sum[right] - sum[left])) > abs((sum[n] - (sum[right+1] - sum[left])) - (sum[right+1] - sum[left]))) {
          ++right;
      }
    chmin(ans , abs((sum[n] - (sum[right] - sum[left])) - (sum[right] - sum[left])));
    if (right == left) ++right;
  }
  cout << ans << endl;
}