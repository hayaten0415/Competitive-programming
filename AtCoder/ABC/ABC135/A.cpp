#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  ll a, b;
  cin >> a >> b;
  if((a + b) % 2 == 0) {
    cout << (a + b) / 2 << endl;
  }else {
    cout << "IMPOSSIBLE" << endl;
  }
}