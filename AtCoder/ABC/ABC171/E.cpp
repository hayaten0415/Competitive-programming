#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll sum = 0;
  int n;
  cin >> n;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i, n){
    cin >> a[i];
    sum = sum ^ a[i];
  }
  rep(i, n){
    ll tmp = sum;
    b[i] = tmp ^ a[i];
  }
  rep(i, n){
    cout << b[i] << (i == n - 1 ? "\n" : " ");
  }
}