#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b;
  cin >> a >> b;
  ll uru_b = b / 4;
  uru_b -= b / 100;
  uru_b += b / 400;
  ll uru_aminus1 = (a - 1) / 4;
  uru_aminus1 -= (a - 1) / 100;
  uru_aminus1 += (a - 1) / 400;
  cout << uru_b - uru_aminus1 << endl;
}