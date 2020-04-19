#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n;
  int ans = 0, count = 0;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  for (int i = 1; i < n; i++) {
    if(a[i] <= a[i - 1]){
      count++;
    } else {
      ans = max(ans, count);
      count = 0;
    }
  }
  ans = max(ans, count);
  cout << ans << endl;
}