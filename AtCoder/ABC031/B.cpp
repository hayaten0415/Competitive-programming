#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int l, h, n;
  cin >> l >> h >> n;
  rep(i,n) {
    int a;
    cin >> a;
    if(a > h){
      cout << -1 << endl;
    }else if(a < l){
      cout << l - a << endl;
    }else {
      cout << 0 << endl;
    }
  }
}