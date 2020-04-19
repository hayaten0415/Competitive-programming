#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n;
  int num;
  double ans;
  cin >> n;
  if(n % 2 == 0) {
    ans = (double)1 / 2;
  }else {
    num = n / 2;
    ans = (double)(num + 1) / n;
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}