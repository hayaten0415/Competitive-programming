#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  double taka = (double)b / a;
  double aoki = (double)d / c;
  if(taka > aoki){
    cout << "TAKAHASHI" << endl;
  }else if (taka < aoki) {
    cout << "AOKI" << endl;
  }else {
    cout << "DRAW" << endl;
  }
}