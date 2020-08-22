#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
ll num[12] = {30, 33, 36, 39, 60, 63, 66, 69, 90, 93, 96, 99};
const ll three[4] = {0,3,6,9};
int ans;
int n;

void dfs(ll num) {
  if(num > n)return;
  ans++;
  rep(i, 4) {
    if(num * 10 + three[i] > n)return;
    dfs(10 * num + three[i]);
  }
}

int main() {
  cin >> n;
  if(n <= 99){
    cout << n / 3 - 3 << endl;
    return 0;
  }
  ans = 30;
  rep(i, 12) {
    rep(j, 4) {
      dfs(num[i] * 10 + three[j]);
    }
  }
  cout << ans << endl;
}