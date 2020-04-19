#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  int sum = 0;
  vector<int> a(m);
  rep(i, m){
    cin >> a[i];
    sum += a[i];
  }
  if(n < sum) {
    cout << -1 << endl;
  }else {
    cout << n - sum << endl;
  }
}