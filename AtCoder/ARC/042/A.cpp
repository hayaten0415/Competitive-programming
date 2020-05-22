#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  rep(i, m) cin >> a[i];
  vector<bool> b(n, false);
  for (int i = m - 1; i >= 0; i--){
    if(!b[a[i] -1]) cout << a[i] << endl, b[a[i] -1] = true;
  }
  rep(i,n){
    if(!b[i]) cout << i + 1 << endl;
  }
}