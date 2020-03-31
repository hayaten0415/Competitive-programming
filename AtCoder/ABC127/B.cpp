#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int r, D, x2000;
  cin >> r >> D >> x2000;
  vector<int> R(10);
  R[0] = r * x2000 - D;
  rep(i, 9){
    R[i + 1] = r * R[i] - D;
  }
  rep(i, 10){
    cout << R[i] << endl;
  }
  return 0;
}