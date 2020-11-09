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
  ll ans = 0;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> sum(n + 1, 0);
  vector<ll> mx_sum(n + 1, 0);
  ll tmp = 0;
  ll mx_tmp = 0;
  rep(i, n){
    sum[i + 1] = sum[i] + A[i];
    chmax(mx_tmp, sum[i + 1]);
    chmax(mx_sum[i + 1], mx_tmp);
  }
  for (int i = 1; i <= n; i++){
    tmp += sum[i];
    chmax(ans, tmp- sum[i] + mx_sum[i]);
  }
  cout << ans << endl;
}