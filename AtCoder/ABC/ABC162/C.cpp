#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int gcd(int a, int b){
  int smaller = min(a, b);
  int bigger = max(a, b);
  int surplus = bigger % smaller;
  if (surplus == 0)
    return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

int main() {
  int k;
  cin >> k;
  int ans = 0;
  for (int i = 1; i <= k; i++){
    for (int j = 1; j <= k; j++){
      for (int t = 1; t <= k; t++){
        ans += gcd(gcd(i, j), t);
      }
    }
  }
  cout << ans << endl;
}