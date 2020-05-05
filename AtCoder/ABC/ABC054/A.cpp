#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b;
  cin >> a >> b;
  if(a == 1) a += 20;
  if(b == 1) b+= 20;
  if(a> b){
    cout << "Alice" << endl;
  }else if(b > a){
    cout << "Bob" << endl;
  }else {
    cout << "Draw" << endl;
  }
}