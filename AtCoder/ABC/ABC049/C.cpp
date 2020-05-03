#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  string tmp_s = "";
  for (int i = s.size() - 1; i >= 0; i--){
    tmp_s += s[i];
    if(tmp_s == "maerd") tmp_s = "";
    else if(tmp_s == "remaerd") tmp_s = "";
    else if(tmp_s == "esare") tmp_s = "";
    else if(tmp_s == "resare") tmp_s = "";
  }
  if(tmp_s == "") cout << "YES" << endl;
  else cout << "NO" << endl;
}