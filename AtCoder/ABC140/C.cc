#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main()
{
  int n;
  int ans = 0;
  cin >> n;
  vector<int> b(n - 1);
  vector<int> a(n);
  rep(i ,n - 1) {
    cin >> b[i];
  }
  rep(i, n) {
    if(i == 0) {
      a[i] = b[i];
    }else if(i == n -1){
      a[i] = b[n - 2];
    }else {
      a[i] = min(b[i], b[i - 1]);
    }
  }
  rep(i ,n) {
    ans += a[i];
  }
  cout << ans << endl;
}