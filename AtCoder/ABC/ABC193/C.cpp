#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  ll n;
  cin >> n; 
  vector<bool> ok(100001, false);
  ll ans = n;
  for (ll i = 2; i * i <= n; i++){
    if(i <= 100000 & ok[i])continue;
    for (ll j = 2; mypow(i, j) <= n; j++){
      ans--;
      if(mypow(i, j) <= 100000)ok[mypow(i,j)] = true;
    }
  }
  cout << ans << endl;
}