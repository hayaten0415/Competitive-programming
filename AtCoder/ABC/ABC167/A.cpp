#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s, t;
  cin >> s >> t;
  bool cond = true;
  rep(i, s.size()){
    if(s[i] != t[i]){
      cond = false;
      break;
    }
  }
  cout << (cond ? "Yes" : "No") << endl;
}