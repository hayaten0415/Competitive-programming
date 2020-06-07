#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  ll ans = 0;
  int n = s.size();
  rep(i,n){
    if(i == 0 || i == n-1){
      ans += n - 1;
    }else{
      if(s[i] == 'U'){
        ans += n - i - 1;
        ans += 2 * i;
      }else{
        ans += i;
        ans += 2 * (n - i - 1);
      }
    }
  }
  cout << ans << endl;
}