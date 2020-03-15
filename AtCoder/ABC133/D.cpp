#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
const long long mod = 2019;
using namespace std;
using ll = long long;

int main() {
  int n;
  ll a_sum = 0;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) {
    cin >> a[i];
    a_sum += a[i];
  }
  rep(i,n) {
    if(i == 0){
      for(int j = i + 1; j < n; j += 2) {
        a_sum -= 2 * a[j];
      }
      b[0] = a_sum;
    }
    if(i < n -1) {
      b[i + 1] = 2 * a[i] - b[i];
    }
    cout << b[i];
    if(i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
}