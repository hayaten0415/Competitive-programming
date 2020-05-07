#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n) cin >> a[i];
  int j = 0;
  int k = n / 2;
  if(n % 2 == 0){
    for (int i = n - 1; i >= 0; i-= 2){
      b[j] = a[i];
      j++;
    }
    for (int i = 0; i < n; i+= 2){
      b[k] = a[i];
      k++;
    }
  }else {
    for (int i = n - 2; i >= 0; i-= 2){
      b[j] = a[i];
      j++;
    }
    for (int i = 0; i < n; i+= 2){
      b[k] = a[i];
      k++;
    }
    reverse(b.begin(), b.end());
  }
  rep(i,n){
    cout << b[i] << (i == n - 1 ? "\n" : " ");
  }
}