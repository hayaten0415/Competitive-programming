#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  cout << max(a * b,c * d) << endl;
}