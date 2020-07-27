#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, h;
  cin >> n >> h;
  ll a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if(h - n * e > 0){
    cout << 0 << endl;
    return 0;
  }
  ll need = e * n - h + 1;
  b += e;
  d += e;
  ll day_a,day_c,left,cost;
  ll all_a = (need+b-1)/b;
  ll min = all_a*a;
  for (day_a = 0; day_a < all_a; day_a++) {
    left = need-day_a*b;
    day_c = (left+d-1)/d;
    cost = day_a*a+day_c*c;
    if (cost < min) {
      min = cost;
    }
  }
  cout << min << endl;
}