#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 1; i <= n; i++){
    if(i % 3 != 0 && i % 5 != 0){
      ans += i;
    }
  }
  cout << ans << endl;
}