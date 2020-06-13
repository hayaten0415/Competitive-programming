#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a, v, b, w, t;
  cin >> a >> v >> b >> w >> t;
  if(a > b){
    ll dis = a - b;
    if((v - w) * t >= dis){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }else{
    ll dis = b - a;
    if((v - w) * t >= dis){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}