#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b;
  char op;
  cin >> a >> op >> b;
  if(op == '+'){
    cout << a + b << endl;
  }else {
    cout << a - b << endl;
  }
  return 0;
}