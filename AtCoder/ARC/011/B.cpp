#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<string> ans;
  rep(i,n){
    string s;
    cin >> s;
    string t = "";
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    rep(j, s.size()){
      if('a' <= s[j] && s[j] <= 'z') {
        if(s[j] == 'b' || s[j] == 'c') t += '1';
        else if(s[j] == 'd' || s[j] == 'w') t += '2';
        else if(s[j] == 't' || s[j] == 'j') t += '3';
        else if(s[j] == 'f' || s[j] == 'q') t += '4';
        else if(s[j] == 'l' || s[j] == 'v') t += '5';
        else if(s[j] == 's' || s[j] == 'x') t += '6';
        else if(s[j] == 'p' || s[j] == 'm') t += '7';
        else if(s[j] == 'k' || s[j] == 'h') t += '8';
        else if(s[j] == 'n' || s[j] == 'g') t += '9';
        else if(s[j] == 'r' || s[j] == 'z') t += '0';
      }
    }
    if(t != "") ans.push_back(t);
  }
  for(int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    if(i != ans.size()-1) cout << " ";
  }
  cout << endl;
}