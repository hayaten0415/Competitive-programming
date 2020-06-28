#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll INF = 1e18;

int main() {
  ll n, m,k;
  cin >> n >> m >> k;
  vector<ll> a(n+1, 0);
  vector<ll> b(m+2, 0);
  b[m+1] = INF;
  rep(i, n){
    ll num;
    cin >> num;
    a[i + 1] = a[i] + num;
  }
  rep(i, m){
    ll num;
    cin >> num;
    b[i + 1] = b[i] + num;
  }
  int ans = 0;
  rep(i, n+1){
    if(a[i] > k){
      break;
    }
    ll tmp = k - a[i];
    int left = 0;
    int right = m+1;
    while (right - left > 1){
      int mid = (left + right) / 2;
      if(tmp >= b[mid]){
        left = mid;
      }else{
        right = mid;
      }
    }
    ans = max(ans, i + left);
  }
  cout << ans << endl;
}