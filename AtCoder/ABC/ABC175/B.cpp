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
  vector<int> L(n);
  rep(i, n) cin >> L[i];
  sort(ALL(L));
  int ans = 0;
  rep(i, n) {
    for (int j = i + 1; j < n; j++){
      for (int k = j + 1; k < n; k++){
        if(L[i] + L[j] <= L[k])continue;
        if(L[i] == L[j])continue;
        if(L[j] == L[k])continue;
        ans++;
      }
    }
  }
  cout << ans << endl;
}