#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  if(a > b){
    cout << 1 << endl;
  }else if (b % a == 0){
    cout << b / a << endl;
  }else {
    cout << b / a + 1 << endl;
  }
}