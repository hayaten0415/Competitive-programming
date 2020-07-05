#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  int mn = 1000000001;
  int ans = 0;
  rep(i , n-1){
    if(mn > abs((a[n - 1] - a[i]) - (a[n-1] / 2))){
      mn = abs((a[n - 1] - a[i]) - (a[n - 1] / 2));
      ans = a[i];
    }
  }
  cout << a[n-1] << " " << ans << endl;
}