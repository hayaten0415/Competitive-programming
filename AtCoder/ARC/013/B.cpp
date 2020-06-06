#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int c;
  cin >> c;
  vector<int> n(c), m(c), l(c);
  vector<int> a(3);
  rep(i, c){
    rep(j, 3) cin >> a[j];
    sort(a.begin(), a.end());
    n[i] = a[0], m[i] = a[1], l[i] = a[2];
  }
  sort(n.begin(), n.end(), greater<int>());
  sort(m.begin(), m.end(), greater<int>());
  sort(l.begin(), l.end(), greater<int>());
  cout << n[0] * m[0] * l[0] << endl;
}