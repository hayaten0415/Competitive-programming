#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  string name, kit;
  cin >> name >> kit;
  vector<int> kit_alphabet(26, 0);
  map<int, int> mp;
  rep(i, m){
    int a = kit[i] - 'A';
    kit_alphabet[a]++;
  }
  rep(i,n){
    int a = name[i] - 'A';
    mp[a]++;
  }
  int ans = 0;
  for (auto k : mp){
    int num = 0;
    if(kit_alphabet[k.first] == 0){
      cout << -1 << endl;
      return 0;
    }
    if(k.second <= kit_alphabet[k.first]){
      num = 1;
    }else {
      num = k.second / kit_alphabet[k.first];
      if(k.second % kit_alphabet[k.first] != 0) num++;
    }
    ans = max(ans, num);
  }
  cout << ans << endl;
}