#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double ans = (double)w * h / 2;
  int cnt = 0;
  if (w % 2 == 0 && w / 2 == x && h % 2 == 0 && h / 2 == y) cnt = 1;
  cout << fixed << setprecision(10) << ans <<  " " << cnt << endl;
}