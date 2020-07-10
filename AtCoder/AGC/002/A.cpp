#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  if(a <= 0 && b >= 0){
    cout << "Zero" << endl;
  }else if (a > 0 && b > 0)  {
    cout << "Positive" << endl;
  }else if(a < 0 && b < 0){
    if((b - a + 1) % 2 == 0){
      cout << "Positive" << endl;
    }else{
      cout << "Negative" << endl;
    }
  }
}