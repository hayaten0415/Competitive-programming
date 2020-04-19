#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n, r;
  cin >> n >> r;
  if(n < 10) {
    cout << r + (10 - n) * 100 << endl;
  } else {
    cout << r << endl;
  }
  return 0;
}