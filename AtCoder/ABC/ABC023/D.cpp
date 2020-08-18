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
  ll left = 0;
  ll right = 1000000000000000000;
  vector<ll> H(n), S(n);
  rep(i, n) cin >> H[i] >> S[i];
  while (right - left > 1){
    ll x = (left + right) / 2;
    vector<ll> tmp(n);
    auto ok = [&](ll x) {
      rep(i, n) {
        if(x < H[i])return false;
        ll second = (x - H[i]) / S[i];
        tmp[i] = second;
      }
      sort(ALL(tmp));
      rep(i, n) {
        if(tmp[i] < i)return false;
      }
      return true;
    };
    if(ok(x))right = x;
    else left = x;
  }
  cout << right << endl;
}