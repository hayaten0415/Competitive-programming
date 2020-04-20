#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  int f = 0;
  int ans = 0;
  cin >> s;
  //+があるところまでで判断するため末尾に+をつける
  s += '+';
  rep(i, s.size()){
    if(s[i] == '0')f++;
    if (s[i] == '+' && f > 0) f= 0;
    else if (s[i] == '+' && f == 0)ans++;
  }
  cout << ans << endl;
}