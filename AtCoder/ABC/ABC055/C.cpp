#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, m;
  cin >> n >> m;
  ll ans = 0;
  ll s_set_c = m / 2;
  if(n >= s_set_c){
    ans += s_set_c;
  }else {
    ans += n;
    m -= 2 * n;
    ans += m / 4;
  }
  cout << ans << endl;
}