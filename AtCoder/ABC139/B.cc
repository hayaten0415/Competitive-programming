#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int a, b;
  cin >> a >> b;
  if(b == 1) {
    cout << 0 << endl;
    return 0;
  }
  if(a >= b) {
    cout << 1 << endl;
    return 0;
  }else {
    for (int i = 2; i <= 100; i++) {
      if(a + (a - 1) * (i - 1) >= b){
        cout << i << endl;
        break;
        return 0;
      }
    }
  }
  return 0;
}