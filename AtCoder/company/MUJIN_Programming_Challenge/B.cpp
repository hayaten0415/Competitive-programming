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

const long double pi = M_PI;

int main() {
  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  ll mx = A[0] + A[1] + A[2];
  sort(ALL(A));
  ll mn = A[2] - A[1] - A[0];
  ll ans = mx;
  ans = ans * ans;
  long double res = (long double)ans * pi;
  if(mn > 0) res -= (long double) mn * (long double)mn * pi;
  cout << fixed << setprecision(10);
  cout << res << endl;
}