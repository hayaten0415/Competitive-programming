#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  bool up = false, down = false;
  rep(i, n) cin >> a[i];
  int cn = 0;
  rep(i,n-1){
    if (a[i] < a[i+1]){
      if(down) {
        cn++, up = false, down = false;
        continue;
      }
      up = true;
    }else if(a[i] > a[i+1]){
      if(up){
        cn++, up = false, down = false;
        continue;
      }
      down = true;
    }
  }
  cn++;
  cout << cn << endl;
}