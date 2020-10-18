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
  ll x, y, a, b;
  cin >> x >> y >> a >> b;
  ll ans = 0;
  while(x * a < b + x && x * a < y && (double)a * x <= 2e18){
    ans++;
    x *= a;
  }
  y -= x;
  ans += y / b;
  if(y % b == 0)ans--;
  cout << ans << endl;
}
