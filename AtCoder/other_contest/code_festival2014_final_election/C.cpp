#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  getline(cin, s);
  int n = s.size();
  set<string> a;
  int i = 0;
  while(i < n){
    if(s[i] == '@'){
      string sub = "";
      while (i++ < n && s[i] >= 'a' && s[i] <= 'z'){
        sub += s[i];
      }
      if(sub.size() > 0) a.insert(sub);
    }else{
      i++;
    }
  }
  for(auto t : a) cout << t << endl;
}