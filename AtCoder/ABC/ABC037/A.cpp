#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << c / min(a, b) << endl;
}