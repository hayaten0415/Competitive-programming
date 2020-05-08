#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  map<ll, int> mp;
  vector<ll> res;
  rep(i, n){
    ll a;
    cin >> a;
    mp[a]++;
  }
  for(auto i : mp){
    if(i.second >= 4){
      res.push_back(i.first);
      res.push_back(i.first);
    }else if(i.second >= 2){
      res.push_back(i.first);
    }
  }
  if(res.size() < 2){
    cout << 0 << endl;
  }else{
    cout << res[res.size() - 1] * res[res.size() - 2] << endl;
  }
  return 0;
}