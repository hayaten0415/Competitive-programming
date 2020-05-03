#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll x;
  cin >> x;
  double rate = 1.01;
  ll money = 100;
  for (int year = 1; year <= 4000; year++){
    money = money * rate;
    if(money >= x){
      cout << year << endl;
      return 0;
    }
  }
}