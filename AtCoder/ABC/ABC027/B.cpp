#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  int ans = 0;
  vector<int> a(n);
  vector<int> sumpeople(n);
  rep(i,n){
    cin >> a[i];
    if(i == 0){
      sumpeople[i] = a[i];
    }else {
      sumpeople[i] = sumpeople[i - 1] + a[i];
    }
    sum += a[i];
  }
  if(sum % n != 0){
    cout << -1 << endl;
    return 0;
  }
  int percount = sum / n;
  rep(i,n - 1){
    if(percount * (i+1) != sumpeople[i]) ans++;
  }
  cout << ans << endl;
}