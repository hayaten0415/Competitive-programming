#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll INF = 100000000000000;

ll nibun_tansaku(ll x){
  ll left = 0;
  ll right = 45000;
  ll key = x;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    ll mid_num = mid * (mid + 1) / 2;
    ll right_num = right * (right + 1) / 2;
    ll left_num = left * (left + 1) / 2;
    if(mid_num <= key ){
      left = mid;
    }else{
      right = mid;
    }
  }
  return left+1;
}

int main() {
  ll x;
  cin >> x;
  ll time = nibun_tansaku(x);
  ll ans = time;
  if(time * (time-1) / 2 == x){
    cout << time - 1 << endl;
    return 0;
  }
  cout << ans << endl;
}