#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, d;
  cin >> a >> d;
  if(a > d){
    cout << a * (d + 1) << endl;
  }else {
    cout << (a + 1) * d << endl;
  }
}