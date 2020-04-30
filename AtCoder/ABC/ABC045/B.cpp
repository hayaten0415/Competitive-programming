#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  char turn = 'a';
  string a, b, c;
  string ans = "";
  cin >> a >> b >> c;
  while(true){
    if(turn == 'a'){
      if(a.size() == 0){
        ans = "A";
        break;
      }else {
        turn = a[0];
        a.erase(0, 1);
      }
    }else if(turn == 'b'){
      if(b.size() == 0){
        ans = "B";
        break;
      }else {
        turn = b[0];
        b.erase(0, 1);
      }
    }else {
      if(c.size() == 0){
        ans = "C";
        break;
      }else {
        turn = c[0];
        c.erase(0, 1);
      }
    }
  }
  cout << ans << endl;
}