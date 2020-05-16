#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int mx = 1000000000;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  int left = 0;
  int right = k - 1;
  ll ans = 1000000000000000;
  rep(i, n) cin >> a[i];
  rep(i,n){
    if(right >= n) break;
    ans = min(ans, abs(a[left]) + abs(a[right] - a[left]));
    ans = min(ans, abs(a[right]) + abs(a[right] - a[left]));
    left++;
    right++;
  }
  cout << ans << endl;
}