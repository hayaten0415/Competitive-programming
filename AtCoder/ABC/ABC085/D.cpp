#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, h;
  cin >> n >> h;
  vector<int> a(n);
  vector<int> b(n);
  rep(i,n){
    cin >> a[i] >> b[i];
  }
  int ans = 0;
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  rep(i,n){
    if(b[i] > a[0]){
      h -= b[i];
      ans++;
    }else {
      break;
    }
    if(h <= 0){
      cout << ans << endl;
      return 0;
    }
  }
  if(h % a[0] != 0){
    ans += h / a[0] + 1;
  }else {
    ans += h / a[0];
  }
  cout << ans << endl;
}