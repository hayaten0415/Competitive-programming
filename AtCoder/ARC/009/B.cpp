#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
 
int main() {
  vector<int> b(10);
  rep(i, 10){
    int a;
    cin >> a;
    b[a] = i;
  }
  int n;
  cin >> n;
  vector<pair<ll, ll>> c(n);
  rep(i,n){
    ll d;
    cin >> d;
    ll real_num = 0;
    ll ten = 1;
    c[i].second = d;
    while(d > 0){
      real_num += b[d % 10] * ten;
      d /= 10;
      ten *= 10;
    }
    c[i].first = real_num;
  }
  sort(c.begin(), c.end());
  rep(i,n){
    cout << c[i].second << endl;
  }
}