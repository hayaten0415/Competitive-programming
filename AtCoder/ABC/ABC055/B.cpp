#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  ll ans = 1;
  rep(i,n){
    ans *= i + 1;
    ans %= mod;
  }
  cout << ans << endl;
}