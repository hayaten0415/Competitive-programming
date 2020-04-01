#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == b){
    cout << 2 * a << endl;
    return 0;
  }
  cout << max(a, b) + max(a, b) - 1 << endl;
  return 0;
}