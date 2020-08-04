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
  ll c, k;
  cin >> c >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(ALL(a));
  ll limit = a[0] + k;
  int ans = 1;
  int pp = 0;
  rep(i, n){
    if(a[i] > limit || pp >= c){
      ans++;
      limit = a[i] + k;
      pp = 1;
    }else{
      pp++;
    }
  }
  cout << ans << "\n";
}