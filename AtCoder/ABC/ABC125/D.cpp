#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  int minus_count = 0;
  priority_queue<ll, vector<ll>, greater<ll>> que;
  ll ans = 0;
  rep(i,n) {
    cin >> a[i];
    if(a[i] < 0) minus_count++;
    que.push(abs(a[i]));
    ans += abs(a[i]);
  }
  if(minus_count % 2 != 0){
    ans -= que.top() * 2;
  }
  cout << ans << endl;
}