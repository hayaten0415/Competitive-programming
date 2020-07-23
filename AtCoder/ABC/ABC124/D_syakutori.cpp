#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int ans = 0;
  int right = 0;
  int cn = 0;
  if (s[0] == '0') cn++;
  for (int left = 0; left < n; ++left){
    while (cn <= k && right < k){
      if(right + 1 < n && s[right] == '1' && s[right +1] == '0')cn++;
      ++right;
    }
    /* break した状態で right は条件を満たす最大なので、何かする */
    ans = max(ans,right - left);

    if (left + 1 < n && s[left] == '0' && s[left + 1] == '1') cn--;
  }
  cout << ans << endl;
}