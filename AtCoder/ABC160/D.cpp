#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = n * (n - 1) / 2 + m * (m - 1) / 2;
  cout << ans << endl;
  return 0;
}