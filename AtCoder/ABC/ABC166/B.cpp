#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  map<int, int> mp;
  rep(i,k){
    cin >> d[i];
    rep(j, d[i]){
      int a;
      cin >> a;
      mp[a]++;
    }
  }
  int ans = 0;
  for (auto i : mp){
    if(i.second > 0)n--;
  }
  cout << n << endl;
}