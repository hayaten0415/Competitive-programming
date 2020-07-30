#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  ll mn = 10000000000000000;
  vector<ll> imos(m + 2, 0);
  rep(i, n){
    int l, r, s;
    cin >> l >> r >> s;
    sum += s;
    imos[l] += s;
    imos[r + 1] -= s;
  }
  rep(i, m){
    imos[i + 1] += imos[i];
  }
  for (int i = 1; i <= m; i++){
    mn = min(mn, imos[i]);
  }
  cout << sum - mn << endl;
}