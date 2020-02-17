#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  bool con = true;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  rep(i,n){
    if(A[i] % 2 == 0){
      if(A[i] % 3 == 0 || A[i] % 5 == 0){
        continue;
      } else {
        con = false;
        break;
      }
    }
  }
  cout << (con ? "APPROVED" : "DENIED") << endl;
  return 0;
}