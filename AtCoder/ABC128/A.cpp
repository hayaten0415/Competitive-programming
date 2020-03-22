#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, p;
  cin >> a >> p;
  int piece = 3 * a + p;
  cout << piece / 2 << endl;
  return 0;
}