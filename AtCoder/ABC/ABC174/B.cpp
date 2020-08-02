#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  ll d;
  cin >> n >> d;
  ll line = pow(d, 2);
  int ans = 0;
  rep(i, n){
    ll a, b;
    cin >> a >> b;
    ll num = pow(a, 2) + pow(b, 2);
    if(num <= line)ans++;
  }
  cout << ans << endl;
}