#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n, 0);
  rep(i, q){
    int l, r, t;
    cin >> l >> r >> t;
    l--; r--;
    for (int j = l; j <= r; j++){
      a[j] = t;
    }
  }
  rep(i,n){
    cout << a[i] << endl;
  }
}