#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  int ans = 0;
  int cnt = 0;
  rep(i, n) {
    if(A[i] == B[i]){
      cnt = 0;
      continue;
    }
    if(cnt == 0 && A[i] != B[i]){
      ans++;
      cnt = 1;
    }
  }
  cout << ans << endl;
}