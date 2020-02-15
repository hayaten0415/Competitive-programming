#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int n, A[50];

bool solve(int i, int m) {
  if(m == 0)return true;
  if(i >= n) return false;
  bool res = solve(i + 1, m) || solve(i + 1, m - A[i]);
  return res;
}

int main() {
  cin >> n;
  int q, M;
  rep(i, n) cin >> A[i];
  cin >> q;
  rep(i, q){
    cin >> M;
    if(solve(0, M)) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}