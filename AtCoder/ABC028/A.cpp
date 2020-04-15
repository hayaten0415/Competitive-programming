#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  if(n == 100) {
    cout << "Perfect" << endl;
  }else if (60 <= n && n < 90){
    cout << "Good" << endl;
  }else if(90 <= n && n < 100) {
    cout << "Great" << endl;
  } else {
    cout << "Bad" << endl;
  }
  return 0;
}