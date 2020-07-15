#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;



int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n){
    cin >> a[i];
  }
  rep(i, n){
    if(a[i] == 0){
      cout << n << endl;
      return 0;
    }
  }
  int ans = 0;
  ll sum = 1;
  int right = 0;
  for (int left = 0; left < n; left++){
    while(right < n && sum * a[right] <= k){
      sum *= a[right];
      right++;
    }
    ans = max(ans,right - left);
    if(right == left)right++;
    else sum /= a[left];
  }
    cout << ans << endl;
}