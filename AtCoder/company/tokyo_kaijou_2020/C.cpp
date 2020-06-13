#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n+1, 0);
  rep(i, n) cin >> a[i];
  rep(ki, k){
    vector<int> b(n + 1);
    rep(i, n){
      int l = max(0, i - a[i]);
      int r = min(n, i + a[i]+1);
      b[l]++; b[r]--;
    }
    rep(i, n) b[i + 1] += b[i];
    b.pop_back();
    if(a == b) break;
    a = b;
  }
  rep(i, n) cout << a[i] << (i == n - 1 ? "\n" : " ");
}