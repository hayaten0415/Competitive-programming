#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  ll sum = 0;
  for (int bit = 0; bit < (1 << s.size() -1); bit++){
    ll num = 0;
    for (int i = 0; i < s.size(); i++){
      num = num * 10 + s[i] - '0';
      if(bit & (1<<i)){
        sum += num;
        num = 0;
      }
    }
    sum += num;
  }
  cout << sum << endl;
}