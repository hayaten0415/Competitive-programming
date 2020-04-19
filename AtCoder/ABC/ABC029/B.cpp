#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int ans = 0;
  rep(i,12){
    string s;
    cin >> s;
    rep(i,s.size()){
      if(s[i] == 'r'){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}