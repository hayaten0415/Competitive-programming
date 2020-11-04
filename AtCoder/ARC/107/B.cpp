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
  ll n, k;
  cin >> n >> k;
  ll ans = 0;
  for (ll i = 2; i <= 2 * n; i++){
    ll rest = i - k;
    if(rest < 2)continue;
    if(rest > 2 * n)continue;
    if(rest - n - 1 > 0)rest -= 2 * (rest - n - 1);
    ll num = i;
    if(num - n - 1 > 0)num -=2 * (num - n- 1) ;
    ans += (rest-1) * (num-1);
  }
  cout << ans << endl;
}