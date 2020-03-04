#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const int MAX =200000;


int main() {
  int n;
  cin >> n;
  cout << (n % 2 == 0? n / 2: n / 2 + 1) << endl;
  return 0;
}