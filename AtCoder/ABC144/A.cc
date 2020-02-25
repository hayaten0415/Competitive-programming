#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const int MAX =200000;

int main() {
  int a, b;
  cin >> a >> b;
  if(a <= 9 && b <= 9) {
    cout << a * b << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}