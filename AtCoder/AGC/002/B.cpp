#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<int> a(n, 1);
  vector<bool> red(n, false);
  red[0] = true;
  rep(i,m){
    int x, y;
    cin >> x >> y;
    x--; y--;
    if(red[x]){
      red[y] = true;
      if(a[x] == 1) red[x] = false;
    }
    a[x]--;
    a[y]++;
  }
  rep(i,n){
    if(red[i] && a[i] > 0)ans++;
  }
  cout << ans << endl;
}