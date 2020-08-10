#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  vector<ll> a(3);
  bool even = false;
  rep(i, 3){
    cin >> a[i];
    if (a[i] % 2 == 0)even = true;
  }
  sort(ALL(a));
  if (even)cout << 0 << endl;
  else cout << a[0] * a[1] << endl;
}