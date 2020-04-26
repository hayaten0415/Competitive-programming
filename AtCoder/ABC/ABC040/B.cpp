#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  int ans = 100000000;
  cin >> n;
  for (int i = 1; i <= sqrt(n); i++){
    int dif = abs(i - (n / i));
    dif += n - (i * (n / i));
    ans = min(ans, dif);
  }
  cout << ans << endl;
}