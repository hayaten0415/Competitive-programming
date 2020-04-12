#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;
  if(n <= 3) {
    cout << 0 << endl;
    return 0;
  }
  ll r = 0;
  ll g = 0;
  ll b = 0;
  rep(i,n){
    if(s[i] == 'R'){
      r++;
    }else if(s[i] == 'G'){
      g++;
    }else {
      b++;
    }
  }
  ll ans = r * g * b;
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      if(s[i] == s[j]) continue;
      int k = j + j - i;
      if(k >= n || s[k] == s[i] || s[k] == s[j]){
        continue;
      }
      ans--;
    }
  }
  cout << ans << endl;
}