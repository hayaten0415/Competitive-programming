#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int w, h, n;
  cin >> w >> h >> n;
  //長方形の左下の座標
  int x1 = 0, y1 = 0;
  //長方形の右上の座標
  int x2 = w, y2 = h;
  rep(i,n){
    int x, y, a;
    cin >> x >> y >> a;
    if(a==1){
      if(x1 <= x) x1 = x;
    }else if(a==2){
      if(x2 >= x) x2 = x;
    }else if(a ==3){
      if(y1 <= y) y1 = y;
    }else {
      if(y2 >= y) y2 = y;
    }
  }
  int ans = (x2 - x1) * (y2 - y1);
  if(x1 > x2 || y1 > y2){
    cout << 0 << endl;
  }else {
    cout << ans << endl;
  }
}