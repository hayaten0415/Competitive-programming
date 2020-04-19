#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i ,n) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  double ans = (double)v[0];
  rep(i,n) {
    if(i > 0){
      ans = (double)(ans + v[i]) / 2;
    }
  }
  cout << fixed << ans << setprecision(5) << endl;
}