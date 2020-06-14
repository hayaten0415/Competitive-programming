#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}


vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
      if (n % i == 0) {
          ret.push_back(i);
          if (i * i != n) ret.push_back(n / i);
      }
  }
  sort(ret.begin(), ret.end()); // 昇順に並べる
  return ret;
}


int main() {
  ll n, p;
  cin >> n >> p;
  if(n == 1){
    cout << p << endl;
    return 0;
  }
  vector<ll> div = divisor(p);
  ll ans = 1;
  for (int i = 1; i < div.size(); i++){
    int cn = 1;
    ll num = div[i];
    while(num * div[i] <= p){
      ll tmp = num;
      num *= div[i];
      //オーバーフロー判定
      if(tmp != num / div[i])break;
      cn++;
    }
    //n乗できるか
    if(cn < n)continue;
    //pをある約数のn乗で割ったときの余りが0でないなら飛ばす
    if(p % mypow(div[i], n) != 0)continue;
    ans = div[i];
  }
  cout << ans << endl;
}