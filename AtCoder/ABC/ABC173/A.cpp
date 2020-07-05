#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int num;
  cin >> num;
  int ans = num % 1000;
  if(ans == 0){
    cout << 0 << endl;
  }else{
    cout << 1000 - ans << endl;
  }
}