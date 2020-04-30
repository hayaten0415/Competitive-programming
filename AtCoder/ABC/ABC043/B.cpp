#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  string ans = "";
  rep(i,s.size()){
    if(s[i] == '0') ans += "0";
    else if(s[i] == '1')ans += "1";
    else {
      if(ans.size() == 0) continue;
      ans.erase(ans.size() - 1);
    }
  }
  cout << ans << endl;
}