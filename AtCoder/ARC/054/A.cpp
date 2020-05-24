#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  double l, x, y, s, d;
  cin >> l >> x >> y >> s >> d;
  double ans = 1e9;
  if(d >= s){
    ans = (d - s) / (x + y);
    if(x < y){
      ans = min(ans, (s + l - d) / (y - x));
    }
  }else{
    ans = (d + l - s) / (x + y);
    if(x < y){
      ans = min(ans, (s - d) / (y - x));
    }
  }
  cout << fixed << setprecision(12) << ans << endl;
}