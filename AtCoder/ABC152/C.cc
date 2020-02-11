#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
int main() {
  int n, ans = 0;
  cin >> n;
  int curmin = 1e9;
  vector<int> P(n);
  rep(i, n) cin >> P[i];
  rep(i,n){
    curmin = min(curmin, P[i]);
    if(curmin == P[i]) ans++;
  }
  cout << ans << endl;
  return 0;
}