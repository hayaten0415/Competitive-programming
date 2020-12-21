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


long long extgcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extgcd(b, a%b, y, x);
    y -= a/b * x;
    return d;
}



int solve() {
  ll n, s, k;
  cin >> n >> s >> k;
  ll d = gcd(gcd(n, s), k);
  n /= d;
  s /= d;
  k /= d;
  if(gcd(n, k) != 1){
    return -1;
  }
  ll x, y;
  extgcd(k, n, x, y);
  x = (x % n + n) % n;
  x *= -s;
  x = (x % n + n) % n;
  return x;
}

int main() {
  int t;
  cin >> t;
  rep(i, t){
    cout << solve() << endl;
  }
}