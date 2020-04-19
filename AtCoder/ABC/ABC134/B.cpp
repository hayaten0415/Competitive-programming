#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, d;
  int ans = 0;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    if(i * (2 * d + 1) >= n) {
      ans = i;
      break;
    }
  }
  cout << ans << endl;
}