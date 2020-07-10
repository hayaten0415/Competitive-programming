#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(2 * n);
  rep(i, 2 * n){
    cin >> a[i];
  }
  int ans = 0;
  sort(a.begin(), a.end());
  for (int i = 0; i < 2 * n; i+= 2){
    ans += a[i];
  }
  cout << ans << endl;
}