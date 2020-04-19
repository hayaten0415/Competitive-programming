#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int x, y, a, b, c;
  ll sum_a = 0;
  ll sum_b = 0;
  cin >> x >> y >> a >> b >> c;
  priority_queue<ll> A;
  priority_queue<ll> B;
  priority_queue<ll> C;
  ll a1, b1, c1;
  ll ans = 0;
  rep(i, a){
    cin >> a1;
    sum_a += a1;
    A.push(a1);
  }
  rep(i,b){
    cin >> b1;
    B.push(b1);
    sum_b += b1;
  }
  rep(i,c){
    cin >> c1;
    C.push(c1);
  }
  rep(i, x){
    ll tmp_a = A.top();
    A.pop();
    C.push(tmp_a);
  }
  rep(i, y){
    ll tmp_b = B.top();
    B.pop();
    C.push(tmp_b);
  }
  rep(i, x + y){
    ans += C.top();
    C.pop();
  }
  cout << ans << endl;
  return 0;
}