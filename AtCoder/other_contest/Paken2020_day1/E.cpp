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
  ll x, y;
  cin >> x >> y;
  if(x == y && x != 0){
    cout << -1 << endl;
    return 0;
  }
  if(x == y && x == 0){
    cout << 1 << " " << 1 << endl;
    return 0;
  }
  if(x == 0){
    cout << 2 * y << " " << y << endl;
  }else if(y == 0){
    cout << x << " " << x * 2 << endl;
  }else{
    ll d = gcd(x, y);
    x /= d;
    y /= d;
    if(x > y){
      cout << x * d << " " << (x + y) * d << endl;
    }else{
      cout << (x + y) * d << " " << y * d << endl;
    }
  }
}