#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h1, m1, h2, m2, k;
  cin >> h1 >> m1 >> h2 >> m2 >> k;
  int a = 60 * h1 + m1;
  int b = h2 * 60 + m2;
  int ans = b - a - k;
  cout << ans << endl;
}