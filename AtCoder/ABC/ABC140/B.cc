#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  int ans = 0;
  cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> c(n - 1);
  rep(i, n) cin >> a[i], a[i]--;
  rep(i, n) cin >> b[i];
  rep(i, n - 1) cin >> c[i];
  rep(i, n) {
    ans += b[a[i]];
    if(i > 0) {
      if(a[i] - 1 == a[i - 1]){
        ans += c[a[i - 1]];
      }
    }
  }
  cout << ans << endl;
}