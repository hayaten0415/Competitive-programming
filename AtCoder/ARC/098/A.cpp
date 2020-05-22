#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> L(n, 0);
  for (int i = 1; i < n; i++){
    if (s[i - 1] == 'W'){
      L[i] = L[i - 1] + 1;
    } else {
      L[i] = L[i - 1];
    }
  }
  vector<int> R(n, 0);
  for (int i = n - 2; i >= 0; i--){
    if (s[i + 1] == 'E'){
      R[i] = R[i + 1] + 1;
    } else {
      R[i] = R[i + 1];
    }
  }
  int ans = n;
  for (int i = 0; i < n; i++){
    ans = min(ans, L[i] + R[i]);
  }
  cout << ans << endl;
}