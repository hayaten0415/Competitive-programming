#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n, a, b;
  cin >> n >> a >> b;
  vector<ll> grid(n);
  vector<ll> tired(n-1, 0);
  int teleport = 0;
  ll ans = 0;
  rep(i,n){
    cin >> grid[i];
    if(i>0){
      tired[i-1] = (grid[i] - grid[i - 1]) * a;
      if(tired[i-1] >= b){
        teleport++;
      }else {
        ans += tired[i-1];
      }
    }
  }
  ans += b * teleport;
  cout << ans << endl;
}