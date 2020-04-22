#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, q;
  cin >> n >> q;
  //いもす法で解いた
  vector<int> a(n+1, 0);
  rep(i, q){
    int l, r;
    cin >> l >> r;
    l--; r--;
    a[l]++;a[r+1]--;
  }
  rep(i,n){
    if(i > 0){
      a[i] += a[i - 1];
    }
  }
  rep(i,n){
    cout << (a[i] % 2 == 0 ? 0 : 1);
  }
  cout << endl;
}