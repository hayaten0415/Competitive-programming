#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, k;
  cin >> n >> k;
  //コーナーケースk==0
  if(k == 0){
    cout << n * n << endl;
    return 0;
  }
  ll ans = n * n;
  //bを固定
  for (int b = 1; b <= n; b++){
    //kがb以上であればn個全てが該当するのでn個引く
    if(b <= k){
      ans -= n;
    //そうでない場合まずnをbで割った商の数×k個引く
    }else {
      int a = n / b;
      ans -= k * a;
      //nをbで割ったあまりとk-1の小さい方をさらに引く
      ans -= min(n % b, k - 1);
    }
  }
  cout << ans << endl;
}