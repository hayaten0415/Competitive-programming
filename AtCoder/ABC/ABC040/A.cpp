#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, x;
  cin >> n >> x;
  cout << min(abs(n - x), abs(x - 1)) << endl;
}
