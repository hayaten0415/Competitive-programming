#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int num1 = c / b;
  int num2 = a / d;
  if (c % b != 0) {
    num1++;
  }
  if(a % d != 0){
    num2++;
  }
  int cou1 = num1;
  int cou2 = num2;
  if(cou1 <= cou2){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}