#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int k, n;
  cin >> k >> n;
  int ans = 0;
  vector<int> A(n);
  rep(i, n){
    cin >> A[i];
  }
  A.push_back(A[0] + k);
  int l = 0;
  rep(i, n){
    l = max(l, A[i + 1] - A[i]);
  }
  ans = k - l;
  cout << ans << endl;
}