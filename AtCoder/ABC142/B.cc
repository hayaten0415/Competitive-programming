#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n, k;
  int ans = 0, num = 0;
  cin >> n >> k;
  rep(i ,n) {
    cin >> num;
    if(num >= k) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}