#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  int m = a % b;
  if(m == 0){
    cout << 0 << endl;
    return 0;
  }
  cout << b - m << endl;
}