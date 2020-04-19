#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> h(n);
  int ans = 1;
  rep(i, n) cin >> h[i];
  int mx = h[0];
  rep(i, n-1){
    if(mx <=  h[i+1]) {
      mx = h[i + 1];
      ans++;
    }
  }
  cout << ans << endl;
}