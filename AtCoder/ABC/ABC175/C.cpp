#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll x, k, d;
  cin >> x >> k >> d;
  ll cn = abs(x) / d;
  ll now = x;
  if(abs(x) >= d){
    if(cn <= k){
      k -= cn;
      if(x > 0){
        now = x - (cn * d);
      }else{
        now = x + (cn * d);
      }
    }else{
      if(x > 0){
        cout << abs(x - (k * d)) << endl;
        return 0;
      }else{
        cout << abs(x + (k * d)) << endl;
        return 0;
      }
    }
  }
  if(k % 2 == 0){
    cout << abs(now) << endl;
  }else{
    cout << min(abs(now-d), abs(now + d)) << endl;
  }
}