#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp;
  rep(i, n){
    mp[a[i]]++;
  }
  int ans = 0;
  for(auto i: mp){
    if(i.second > i.first){
      ans += i.second - i.first;
    }else if(i.second < i.first){
      ans += i.second;
    }
  }
  cout << ans << endl;
}