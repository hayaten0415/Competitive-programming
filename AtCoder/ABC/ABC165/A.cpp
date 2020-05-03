#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int k;
  int a, b;
  cin >> k >> a >> b;
  bool cond = false;
  for (int i = a; i <= b; i++){
    if(i % k == 0){
      cond = true;
      break;
    }
  }
  cout << (cond ? "OK" : "NG") << endl;
}