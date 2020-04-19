#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n, x, num;
  int ans = 0;
  cin >> n >> x;
  vector<int> L(n + 1);
  L[0] = 0;
  for (int i = 1; i < n + 1; i++){
    cin >> num;
    L[i] = L[i - 1] + num;
  }
  rep(i, n + 1){
    if(L[i] > x){
      break;
    }else {
      ans++;
    }
  }
  cout << ans << endl;
}