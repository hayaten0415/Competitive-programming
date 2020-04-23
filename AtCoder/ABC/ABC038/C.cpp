#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 1;
  int plus = 1;
  rep(i,n-1){
    if(a[i+1] > a[i]){
      plus++;
      ans += plus;
    }else {
      plus = 1;
      ans++;
    }
  }
  cout << ans << endl;
}