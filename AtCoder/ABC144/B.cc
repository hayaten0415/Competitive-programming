#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const int MAX =200000;

int main() {
  int n = 0;
  cin >> n;
  for (int i = 9; i >= 2; i--){
    if(n % i == 0){ 
      n /= i;
      break;
    }
  }
  cout << (n < 10 ? "Yes" : "No") << endl;
  return 0;
}