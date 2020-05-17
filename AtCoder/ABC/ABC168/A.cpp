#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int ans = n % 10;
  if(ans == 3){
    cout << "bon" << endl;
  }else if(ans == 1 || ans == 0 || ans == 6 || ans == 8){
    cout << "pon" << endl;
  }else {
    cout << "hon" << endl;
  }
}