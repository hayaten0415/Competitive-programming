#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int k;
  cin >> k;
  if(c > b && b > a){
    cout << "Yes" << endl;
    return 0;
  }
  rep(i, k){
    if(c > b && b > a){
      cout << "Yes" << endl;
      return 0;
    }
    if(b <= a){
      b *= 2;
      continue;
    }
    if(c <= b){
      c *= 2;
      continue;
    }
  }
  if(c > b && b > a){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}