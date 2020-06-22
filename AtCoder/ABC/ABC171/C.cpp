#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  ll n;
  cin >> n;
  n--;
  ll cn = 1;
  ll tmp = n;
  string ans = "";
  while (n >= 0){
    int num = n % 26;
    char b = num + 'a';
    ans += b;
    n /= 26;
    n--;
  }
  reverse(ans.begin(), ans.end());
  cout << ans << endl;
}