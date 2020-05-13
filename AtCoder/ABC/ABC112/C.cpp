#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> x(n), y(n), h(n);
  int ax, by, ch;
  rep(i, n){
    cin >> x[i] >> y[i] >> h[i];
    if(h[i] > 0){
      ax = x[i];
      by = y[i];
      ch = h[i];
    }
  } 
  rep(tx,101){
    rep(ty,101){
      bool ok = true;
      int H = ch + abs(tx - ax) + abs(ty - by);
      rep(i,n){
        if(h[i] != max(H - abs(tx - x[i]) - abs(ty- y[i]), 0)){
          ok = false;
          break;
        }
      }
      if(ok){
        cout << tx << " " << ty << " " << H << endl;
        return 0;
      }
    }
  }
}