#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  ll a, b;
  cin >> n >> a >> b;
  ll mx = 0, mn = 10000000000000;
  ll sum = 0;
  vector<ll> s(n);
  rep(i,n) {
    cin >> s[i];
    sum += s[i];
    mx = max(mx, s[i]);
    mn = min(mn, s[i]);
  }
  if(mx == mn){
    cout << -1 << endl;
    return 0;
  }
  double p = (double)b / (mx - mn);
  double q = (double)(a * n - sum * p) / n;
  printf("%.10f", p);
  cout << " ";
  printf("%.10f", q);
}