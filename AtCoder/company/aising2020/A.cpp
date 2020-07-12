#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int l, r, d;
  cin >> l >> r >> d;
  cout << (r / d) - ((l-1) / d) << endl;
}