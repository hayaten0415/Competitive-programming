#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int x;
  cin >> x;
  int fifth = x / 500;
  int fir = (x - fifth * 500) / 5;
  cout << 5 * fir + fifth * 1000 << endl;
  return 0;
}