#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
const long long INF = 100000000000;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  map<ll,int> mp;
  rep(i,n){
    ll num;
    cin >> num;
    mp[num]++;
  }
  ll ans = 0;
  for(auto i: mp){
    if(i.second % 2 == 1) ans++;
  }
  cout << ans << endl;
}