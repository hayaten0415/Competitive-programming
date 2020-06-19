#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int k, t;
  cin >> k >> t;
  vector<int> a(t);
  int mx = 0;
  int sum = 0;
  rep(i, t){
    cin >> a[i];
    mx = max(mx, a[i]);
    sum += a[i];
  }
  if(2 * mx - sum > 1){
    cout << 2 * mx - sum - 1 << endl;
  }else{
    cout << 0 << endl;
  }
}