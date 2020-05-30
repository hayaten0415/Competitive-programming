#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string t;
  cin >> t;
  if(t.size() == 1){
    if(t[0] == 'P'){
      cout << t << endl;
      return 0;
    }else {
      cout << "D" << endl;
      return 0;
    }
  }
  rep(i, t.size()){
    if(t[i] == '?'){
      //if(i + 1 < t.size() && (t[i+1] == 'D' || t[i+1] == '?')){
      //  t[i] = 'P';
      //  t[i+1] = 'D';
      //}else {
      //  t[i] = 'D';
      //}
      t[i] = 'D';
    }
  }
  cout << t << endl;
}