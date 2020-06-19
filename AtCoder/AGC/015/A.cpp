#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  if(a > b){
    cout << 0 << endl;
    return 0;
  }else if(a == b){
    cout << 1 << endl;
    return 0;
  }
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }else if(n == 2){
    cout << 1 << endl;
    return 0;
  }
  ll num = n - 2;
  cout << (b - a) * num + 1 << endl;
}