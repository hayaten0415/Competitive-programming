#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n-1);
  vector<int> ans(n);
  rep(i, n-1) cin >> a[i];
  if(a[0] > a[1]){
    ans[0] = a[0];
  }else{
    ans[0] = 1;
  }
  for (int i = 1; i < n; i++){
    if(a[i] >= a[i-1]){
      ans[i] = a[i - 1];
    }else{
      if(i == n-1)ans[i] = a[i-1];
      else ans[i] = a[i];
    }
  }
  rep(i,n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}