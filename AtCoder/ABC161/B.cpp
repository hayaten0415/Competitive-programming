#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  int sum = 0;
  bool cond = true;
  cin >> n >> m;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
    sum += a[i];
  }
  sort(a.begin(),a.end());
  double num = (double)a[n - m] / sum;
  if(num < (double)1 / (4 * m) ){
    cond = false;
  }
  cout << (cond ? "Yes" : "No") << endl;
}