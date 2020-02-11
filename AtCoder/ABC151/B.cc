#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main(){
  int n, k, m, sum = 0, ans = 0;
  cin >> n >> k >> m;
  vector<int> A(n - 1);
  rep(i, n - 1){
    cin >> A[i];
    sum += A[i];
  }
  if(m * n > sum){
    if(m * n - sum <= k){
      ans = m * n - sum;
    }else {
      ans = -1;
    }
  }
  cout << ans << endl;
  return 0;
}
