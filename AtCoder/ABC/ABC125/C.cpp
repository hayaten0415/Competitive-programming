#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int gcd(int a, int b) {
  int smaller = min(a, b);
  int bigger = max(a, b);
  if(smaller == 0) return bigger;
  int surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  if(n == 2){
    cout << a[1] << endl;
    return 0;
  }
  sort(a.begin(), a.end());
  vector<int> left(n + 1, 0), right(n + 1, 0);
  for (int i = 0; i < n; ++i) left[i+1] = gcd(left[i], a[i]);
  for (int i = n-1; i >= 0; --i) right[i] = gcd(right[i+1], a[i]);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    // 左側
    int l = left[i];
    // 右側
    int r = right[i + 1];
    // 更新
    ans = max(ans, gcd(l, r));
  }
  cout << ans << endl;
}