#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll b = 1;
  ll a = 2;
  rep(i, n-1){
    ll num1 = a;
    ll num2 = b;
    b = num1;
    a = num1 + num2;
  }
  cout << a << " " << b << endl;
}
