#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  int k;
  cin >> s >> k;
  ll ans = 0;
  if(s == string(s.size(), s[0])){
    cout << s.size() * k / 2 << endl;
    return 0;
  }
  ll cnt1 = 0;
  ll cnt2 = 0;
  string tmp = s + s;
  rep(i, s.size()-1){
    if(s[i] == s[i+1]) s[i+ 1] = '&',cnt1++;
  }
  rep(i, tmp.size() -1){
    if(tmp[i] == tmp[i+1]) tmp[i+1] = '&',cnt2++;
  }
  cout << cnt1 + (cnt2 - cnt1) * (k - 1) << endl;
}