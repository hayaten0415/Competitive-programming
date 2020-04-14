#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  double ans = 0;
  rep(i,n){
    double a;
    string b;
    cin >> a >> b;
    if(b == "JPY") ans += a;
    else ans += a * 380000;
  }
  cout << ans << endl;
}