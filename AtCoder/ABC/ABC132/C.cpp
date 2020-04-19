#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  int ans = 0;
  cin >> n;
  vector<int> a(n);
  rep(i ,n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if(a[n / 2 - 1] == a[n /2]){
    cout << 0 << endl;
    return 0;
  }else {
    for (int i = a[n / 2 - 1] + 1; i <= a[n / 2]; i++){
      ans++;
    }
  }
  cout << ans << endl;
}