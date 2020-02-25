#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


//10の9まで売られてる

ll binarySearch(ll a, ll b, ll x){
  ll left = 0;
  ll right = 1000000000;
  string s = std::to_string(right);
  ll bitnum = s.size();
  ll ans = 0;
  ll mid;
  if (right * a + bitnum * b <= x){
    return right;
  } 
  while (left < right){
    mid = (left + right) / 2;
    s = to_string(mid);
    bitnum = s.size();
    if(right - left <= 1) break;
    if (mid * a + bitnum * b <= x) {
      left = mid;
      ans = mid;
    } else {
      right = mid;
    }
  }
  return ans;
}

int main() {
  ll a, b;
  ll x;
  ll ans = 0;
  cin >> a >> b >> x;
  ans = binarySearch(a, b, x);
  cout << ans << endl;
  return 0;
}