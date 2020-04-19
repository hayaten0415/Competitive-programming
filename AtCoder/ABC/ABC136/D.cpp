#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  string s;
  cin >> s;
  int num = 0;
  vector<int> div;
  bool nondiv = false;
  char c = s.at(0);
  rep(i, s.size() - 1){
    if(!nondiv) {
      if(c == s.at(i + 1)) {
        continue;
      }else {
        nondiv = true;
      }
    }else {
      if(c == s.at(i + 1)) {
        continue;
      }else {
        nondiv = false;
        div.push_back(i);
      }
    }
    c = s.at(i + 1);
  }
}