#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x, y;
  cin >> x >> y;
  if(x == 0){
    if(y <0){
      cout << abs(y) + 1 << endl;
      return 0;
    }else{
      cout << y << endl;
      return 0;
    }
  }
  if(y == 0){
    if(x < 0){
      cout << abs(x) << endl;
      return 0;
    }else{
      cout << x + 1 << endl;
      return 0;
    }
  }
  if(x >= 0 && y >= 0){
    if(y >x){
      cout << y - x << endl;
      return 0;
    }else{
      cout << x + y << endl;
      return 0;
    }
  }
  if(x <= 0 && y >= 0){
    if(abs(x) <= abs(y)){
      cout << 1 + abs(y) - abs(x) << endl;
      return 0;
    }else{
      cout << abs(x) - abs(y) + 1 << endl;
      return 0;
    }
  }
  if(x >= 0 && y <= 0){
    if (abs(x) <= abs(y)){
      cout << abs(y) - abs(x) + 1 << endl;
      return 0;
    }else{
      cout << abs(x) - abs(y) + 1 << endl;
      return 0;
    }
  }
  if(x <= 0 && y <= 0){
    if (abs(x) <= abs(y)){
      cout << abs(y) - abs(x) + 2 << endl;
      return 0;
    }else{
      cout << abs(x) - abs(y) << endl;
      return 0;
    }
  }
}