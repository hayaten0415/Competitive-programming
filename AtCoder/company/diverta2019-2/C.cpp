#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> plus;
  vector<ll> minus;
  vector<ll> a(n);
  ll sum = 0;
  ll plus_sum = 0;
  ll minus_sum = 0;
  rep(i, n){
    ll num;
    cin >> num;
    a[i] = num;
    sum += abs(num);
    if(num >= 0){
      plus.push_back(num);
      plus_sum += num;
    }else{
      minus.push_back(num);
      minus_sum += num;
    }
  }
  if(n == 2){
    cout << max(a[0], a[1]) - min(a[0], a[1]) << endl;
    cout << max(a[0], a[1]) << " " << min(a[0], a[1]) << endl;
    return 0;
  }
  sort(ALL(plus));
  sort(ALL(minus));
  if (plus.size() == n){
    ll num = plus_sum - 2 * plus[0];
    cout << num << endl;
    ll tmp = plus[0] - plus[plus.size() -1];
    rep(i, n-1){
      if(i == 0){
        cout << plus[0] << " " << plus[plus.size() - 1] << endl;
      }else if(i != n-2){
        cout << tmp << " " << plus[plus.size() - 1 - i] << endl;
        tmp -= plus[plus.size() - 1 - i];
      }else{
        cout << plus[1] << " " << tmp << endl;
      }
    }
    return 0;
  }
  if(minus.size() == n){
    ll num = abs(minus_sum) - 2 * abs(minus[minus.size() -1]);
    cout << num << endl;
    ll tmp = minus[minus.size() - 1]- minus[0];
    rep(i, n-1){
      if(i == 0){
        cout << minus[minus.size() - 1] << " " << minus[0] << endl;
      }else{
        cout << tmp << " " << minus[i] << endl;
        tmp -= minus[i];
      }
    }
    return 0;
  }
  cout << sum << endl;
  int mn = min(plus.size(), minus.size());
  ll tmp1 = plus[mn - 1];
  ll tmp2 = minus[mn -1];
  rep(i, n-1){
    if(plus.size() <= minus.size()){
      if(i < mn-1){
        cout << minus[i] << " " << plus[i] << endl;
        minus.push_back(minus[i] - plus[i]);
      }else{
        if(i == mn-1){
          cout << plus[mn - 1] << " " << minus[i] << endl;
        }else{
          cout << tmp1 << " " << minus[i] << endl;
        }
        tmp1 -= minus[i];
      }
    }else{
      if(i < mn-1){
        cout << plus[i] << " " << minus[i] << endl;
        plus.push_back(plus[i] - minus[i]);
      }else if(i >= mn -1 && i != n-2){
        cout << tmp2 << " " << plus[i] << endl;
        tmp2 -= plus[i];
      }else{
        cout << plus[i] << " " << tmp2 << endl;
      }
    }
  }
}
