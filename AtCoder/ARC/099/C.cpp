#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  if (n <= k){
    cout << 1 << endl;
    return 0;
  }
  int ans = (n-1) / (k - 1);
  int b = n-1;
  int c = k-1;
  if(b % c != 0)ans++;
  cout << ans << endl;
}