#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  cout << (b % a == 0 ? a + b : b -a) << endl;
}