#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int l1, l2, l3;
  cin >> l1 >> l2 >> l3;
  int ans = 0;
  if(l1 == l2) ans = l3;
  if(l2 == l3) ans = l1;
  if(l3 == l1) ans = l2;
  cout << ans << endl;
}