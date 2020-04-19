#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int k, x;
  cin >> k >> x;
  int i = x - k + 1;
  while (i <= x + k - 1) {
    cout << i;
    if(i < x + k - 1) {
      cout << " ";
    }
    i++;
  }
  cout << endl;
}