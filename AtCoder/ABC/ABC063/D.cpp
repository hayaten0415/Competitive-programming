#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

vector<ll> hp;
int n;
ll a, b;
//t回で倒せるか
bool enough(ll t){
  ll cnt = 0;
  ll bigger_count  = 0;
  rep(i,n){
    if(hp[i] - b * t >0){
      bigger_count++;
    }
  }
  rep(i,bigger_count){
    ll rest = hp[i] - b * t;
    if(rest % (a-b) != 0){
      cnt += rest / (a - b) + 1;
    }else {
      cnt += rest / (a - b);
    }
  }
  if(cnt <= t){
    return true;
  }else {
    return false;
  }
}

int main() {
  cin >> n >> a >> b;
  hp.assign(n, 0);
  rep(i, n) cin >> hp[i];
  sort(hp.begin(), hp.end(), greater<ll>());
  ll high = 1000000010;
  ll low = 0;
  ll ans = 0;
  while(high - low > 0){
    ll mid = (high + low) / 2;
    if(high - low == 1){
      if(enough(mid)) ans = low;
      else ans = low + 1;
      break;
    }
    if(enough(mid)){
      high = mid;
    }else {
      low = mid;
    }
  }
  cout << ans << endl;
}