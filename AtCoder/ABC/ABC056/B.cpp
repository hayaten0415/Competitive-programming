#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int w, a, b;
  cin >> w >> a >> b;
  if (a <= b && b <= a + w){
    cout << 0 << endl;
    return 0;
  }
  if(a + w < b){
    cout << b - a - w << endl;
  }else{
    cout << a - b - w << endl;
  }
}