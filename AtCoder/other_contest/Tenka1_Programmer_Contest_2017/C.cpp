#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n;
  cin >> n;
  for (ll i = 1; i <= 3500; i++){
    for (ll j = 1; j <= 3500; j++){
      ll numerator = i * j * n;
      ll denominator = 4 * i * j - n * (i + j);
      if(denominator <= 0)continue;
      if(numerator % denominator == 0){
        ll num = numerator / denominator;
        cout << i << " " << j << " " << num << endl;
        return 0;
      }
    }
  }
}