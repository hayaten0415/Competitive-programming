#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  if(a >= k){
    cout << k << endl;
  }else if (a + b >= k){
    cout << a << endl;
  }else{
    cout << a - (k - a - b) << endl;
  }
}