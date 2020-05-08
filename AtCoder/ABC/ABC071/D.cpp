#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  string s1, s2;
  cin >> s1 >> s2;
  int r = 0;
  int a = 1;
  int b = -1;
  ll ans = 1;
  while(1){
    if(r>= n) break;
    if(s1[r] == s2[r]){
      a = 1;
      r++;
    }else {
      a = 0;
      r += 2;
    }
    if(b == -1 && a == 1) ans *= 3;
    else if(b == -1 && a == 0) ans *= 6;
    else if(b == 1 && a == 1) ans *= 2;
    else if(b == 1 && a == 0) ans *= 2;
    else if(b == 0 && a == 1) ans *= 1;
    else if(b == 0 && a == 0) ans *= 3;
    ans %= mod;
    b = a;
  }
  cout << ans << endl;
}