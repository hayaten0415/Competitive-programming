#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll d = c - a - b;
  if(d > 0 && d * d > 4 * a * b){
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}