#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main(){
  ll n, k;
  cin >> n >> k;
  map<ll, ll> mp;
  rep(i,n){
    ll a, b;
    cin >> a >> b;
    mp[a] += b;
  }
  ll num = 0;
  for(auto n : mp){
    num += n.second;
    if(num >= k){
      cout << n.first << endl;
      return 0;
    }
  }
}