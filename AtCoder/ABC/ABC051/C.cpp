#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int sx, sy, tx, ty;
  cin >> sx >> sy >> tx >> ty;
  string ans = "";
  rep(i, ty - sy){
    ans += 'U';
  }
  rep(i, tx-sx){
    ans += 'R';
  }
  rep(i, ty-sy){
    ans += 'D';
  }
  rep(i, tx-sx){
    ans += 'L';
  }
  ans += "L";
  rep(i, ty-sy+1){
    ans += "U";
  }
  rep(i, tx-sx+1){
    ans += "R";
  }
  ans += "DR";
  rep(i, ty-sy+1){
    ans += "D";
  }
  rep(i, tx-sx+1){
    ans += "L";
  }
  ans += "U";
  cout << ans << endl;
}