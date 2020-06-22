#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  map<ll, ll> mp;
  ll sum = 0;
  rep(i, n){
    cin >> a[i];
    mp[a[i]]++;
    sum += (ll)a[i];
  }
  int q;
  cin >> q;
  rep(i, q){
    ll b, c;
    cin >> b >> c;
    if(mp[b] == 0){
      cout << sum << endl;
    }else{
      ll tmp = mp[b];
      mp[b] = 0;
      sum -= b * tmp;
      mp[c] += tmp;
      sum += c * tmp;
      cout << sum << endl;
    }
  }
}