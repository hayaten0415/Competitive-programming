#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  ll sum_a = 0;
  ll sum_b = 0;
  vector<int> a(n);
  vector<int> b(n);
  vector<int> mx;
  rep(i, n){
    cin >> a[i];
    sum_a += a[i];
  }
  rep(i, n){
    cin >> b[i];
    sum_b += b[i];
  }
  if(sum_a < sum_b){
    cout << -1 << endl;
    return 0;
  }
  int ans = 0;
  ll minus_sum = 0;
  rep(i, n){
    if(b[i] > a[i]){
      ans++;
      minus_sum += abs(a[i] - b[i]);
    }else if(a[i] > b[i]){
      mx.push_back(a[i] - b[i]);
    }else{
      continue;
    }
  }
  sort(mx.begin(), mx.end(), greater<int>());
  vector<ll> mx_sum(mx.size() + 1, 0);
  rep(i, mx.size()){
    mx_sum[i + 1] += mx_sum[i] + mx[i];
  }
  auto ite = lower_bound(mx_sum.begin(), mx_sum.end(), minus_sum);
  ans += (int)distance(mx_sum.begin(), ite);
  cout << ans << endl;
}