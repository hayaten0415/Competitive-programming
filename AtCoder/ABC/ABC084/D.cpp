#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

//素数判定
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
  int q;
  cin >> q;
  vector<int> res(100001, 0);
  for (int i = 3; i <= 100000; i+=2){
    if(isPrime(i) && isPrime((i + 1)/ 2)){
      res[i] = 1;
    }else {
      res[i] = 0;
    }
  }
  rep(i, 100000){
    res[i] += res[i-1];
  }
  rep(i, q){
    int l, r;
    cin >> l >> r;
    cout << res[r] - res[l - 1] << endl;
  }
}