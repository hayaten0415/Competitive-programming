#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> T(n);
  vector<ll> A(n);
  rep(i,n){
    cin >> T[i] >> A[i];
  }
  ll num1 = 1;
  ll num2 = 1;
  rep(i,n){
    ll n1 = num1 / T[i];
    ll n2 = num2 / A[i];
    if(num1 % T[i] != 0) n1++;
    if(num2 % A[i] != 0) n2++;
    ll n = max(n1, n2);
    num1 = T[i] * n; num2 = A[i] * n;
  }
  cout << num1 + num2 << endl;
}