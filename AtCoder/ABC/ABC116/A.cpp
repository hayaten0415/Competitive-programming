#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << min(a * b, min(b * c, c * a)) / 2 << endl;
}