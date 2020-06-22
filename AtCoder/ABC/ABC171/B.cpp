#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> b(n);
  rep(i, n) cin >> b[i];
  int ans = 0;
  sort(b.begin(), b.end());
  rep(i, k) ans += b[i];
  cout << ans << endl;
  
}