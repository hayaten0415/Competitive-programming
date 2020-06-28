#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  vector<ll> a(n+ 1, 0);
  ll ans = 0;
  //調和級数によるO(NlogN)解法
  //ABC170Dと同じ
  for (int i = 1; i <= n; i++){
    for (int j = i; j <= n; j += i){
      a[j]++;
    }
  }
  for (int i = 1; i <= n; i++){
    ans += a[i] * i;
  }
  cout << ans << endl;
}
