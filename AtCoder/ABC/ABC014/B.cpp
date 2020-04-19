#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, x;
  int ans = 0;
  cin >> n >> x;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(k,n){
    //k番目のビットが立っているか
    if(x >> k & 1){
      ans += a[k];
    }
  }
  cout << ans << endl;
}