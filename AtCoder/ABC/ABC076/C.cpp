#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  string t;
  vector<int> kouho;
  vector<int> kouho2;
  vector<string> res;
  cin >> s >> t;
  if(t.size() > s.size()){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  rep(i,s.size()-t.size() + 1){
    if(s[i] == t[0] || s[i] == '?'){
        kouho.push_back(i);
    }
  }
  rep(i, kouho.size()){
    rep(j,t.size()){
      if(s[kouho[i] + j] == t[j] || s[kouho[i] + j] == '?'){
        if(j == t.size() -1){
          kouho2.push_back(kouho[i]);
        }
      }else {
        break;
      }
    }
  }
  if(kouho2.size() == 0){
    cout << "UNRESTORABLE" << endl;
    return 0;
  }
  rep(i, kouho2.size()){
    string tmp = s;
    for (int j = 0; j < t.size(); j++){
      tmp[kouho2[i] + j] = t[j];
    }
    rep(i,tmp.size()){
      if(tmp[i] == '?') tmp[i] = 'a';
    }
    res.push_back(tmp);
  }
  sort(res.begin(), res.end());
  cout << res[0] << endl;
}