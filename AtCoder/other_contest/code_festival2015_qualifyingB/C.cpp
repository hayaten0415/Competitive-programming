#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  if(m > n){
    cout << "NO" << endl;
    return 0;
  }
  vector<int> a(n);
  vector<int> b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  sort(a.begin(), a.end(), greater<int>());
  sort(b.begin(), b.end(), greater<int>());
  rep(i,m){
    if(a[i] < b[i]){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}