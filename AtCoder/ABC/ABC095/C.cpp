#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c, x, y;
  cin >> a >> b >> c >> x >> y;
  ll ans = 0;
  if(a + b >= 2 * c){
    ans += min(x, y) * c * 2;
  }else{
    cout << a * x + b * y << endl;
    return 0;
  }
  int mn = min(x, y);
  x -= mn;
  y -= mn;
  if (x > 0){
    if(a > 2 * c){
      ans += 2 * c * x;
    }else{
      ans += a * x;
    }
  }else if(y > 0){
    if(b > 2 * c){
      ans += 2 * c * y;
    }else{
      ans += b * y;
    }
  }
  cout << ans << endl;
}