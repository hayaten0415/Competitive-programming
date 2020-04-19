#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= 3; i++){
    if(i == n || i == m) continue;
    cout << i << endl;
  }
  return 0;
}