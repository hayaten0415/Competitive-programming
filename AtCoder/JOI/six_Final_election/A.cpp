#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  ll mx = -1000000000000000;
  vector<ll> sum(n + 1, 0);
  rep(i,n){
    ll num;
    cin >> num;
    sum[i + 1] = sum[i] + num;
  }
  for (int i = k; i < n + 1; i++){
    mx = max(mx, sum[i] - sum[i - k]);
  }
  cout << mx << endl;
}