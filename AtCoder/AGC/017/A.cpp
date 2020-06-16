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

//参考http://izumi-math.jp/I_Yanagita/binomial_theorem1.pdf

int main() {
  ll n, p;
  cin >> n >> p;
  int odd_number_count = 0;
  rep(i, n) {
    int a;
    cin >> a;
    if (a % 2 != 0)odd_number_count++;
  }
  if(odd_number_count == 0){
    if(p == 0){
      cout << mypow(2, n) << endl;
      return 0;
    }else {
      cout << 0 << endl;
      return 0;
    }
  }
  cout << mypow(2, n - 1) << endl;
}