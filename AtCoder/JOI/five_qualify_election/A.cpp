#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll a = 0, b = 0;
  int n;
  cin >> n;
  rep(i, n) {
    int x, y;
    cin >> x >> y;
    if(x > y){
      a += x + y;
    }else if(x < y){
      b += x + y;
    }else {
      a += x;
      b += y;
    }
  }
  cout << a << " " << b << endl;
}