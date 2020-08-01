#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll MOD = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  ll ans = 0;
  ll tmp = (k * (k - 1) / 2) % MOD;
  for(int i = 0; i < n; i++){
    int f = 0, b = 0;
    for(int j = 0; j < i; j++){
        if(a[i] > a[j]) f++;
    }
    for(int j = i + 1; j < n; j++){
        if(a[i] > a[j]) b++;
    }
    ans = (ans + (b * k) + ((b + f) * tmp)) % MOD;
  }
  cout << ans << endl;
}