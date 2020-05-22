#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  map<char, int> mp;
  rep(i,s.size()){
    mp[s[i]]++;
  }
  int k = 0;
  for(auto i: mp){
    if(i.second % 2 != 0){
      k++;
    }
  }
  if(k == 0){
    cout << s.size() << endl;
  }else{
    int ans = 2 * (((int)s.size() - k) / (2 * k)) + 1;
    cout << ans << endl;
  }
}