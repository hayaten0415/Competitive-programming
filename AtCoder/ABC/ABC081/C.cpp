#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  map<int, int> mp;
  priority_queue<int, vector<int>, greater<int>> que;
  rep(i,n){
    int a;
    cin >> a;
    mp[a]++;
  }
  if(mp.size() <= k){
    cout << 0 << endl;
    return 0;
  }
  for(auto i: mp){
    que.push(i.second);
  }
  int ans = 0;
  rep(i, mp.size() - k){
    ans += que.top(); que.pop();
  }
  cout << ans << endl;
}