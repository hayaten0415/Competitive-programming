#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll first_plus = 0;
  ll first_minus = 0;
  ll sum1 = 0;
  ll sum2 = 0;
  for (int i = 0; i < n; i++){
    if(i % 2 == 0){
      sum1 += a[i];
      if(sum1 <= 0){
        first_plus += abs(sum1 - 1);
        sum1 = 1;
      }
      sum2 += a[i];
      if(sum2 >= 0){
        first_minus += abs(sum2 + 1);
        sum2 = -1;
      }
    }else{
      sum1 += a[i];
      if(sum1 >= 0){
        first_plus += abs(sum1 + 1);
        sum1 = -1;
      }
      sum2 += a[i];
      if(sum2 <= 0){
        first_minus += abs(sum2 - 1);
        sum2 = 1;
      }
    }
  }
  cout << min(first_plus, first_minus) << endl;
}