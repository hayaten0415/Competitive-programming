#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (a - (2 * b) > 0 ? a - (2 * b) : 0) << endl;
  return 0;
}