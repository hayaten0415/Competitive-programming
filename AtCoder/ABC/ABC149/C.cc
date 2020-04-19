#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

bool isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0) {
        // 素数ではない
        return false;
      }
    }
    // 素数である
    return true;
}

int main() {
  int x;
  int ans = 0;
  cin >> x;
  for (int i = x; i <= 1000000; i++){
    if(isPrime(i)){
      ans = i;
      break;
    }
  } 
  cout << ans << endl;
  return 0;
}