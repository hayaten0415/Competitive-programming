#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> t;
  vector<int> three;
  map<int, int> mp;
  rep(i, n){
    cin >> a[i];
    mp[a[i]]++;
  }
  if(mp.size() > 3){
    cout << "No" << endl;
    return 0;
  }
  if(mp.size() == 1){
    if(mp[0] != n){
      cout << "No" << endl;
    }else {
      cout << "Yes" << endl;
    }
  }else if(mp.size() == 2){
    for(auto v: mp){
      t.push_back(v.first);
    }
    if(mp[t[1]] == 2 * mp[0] && mp[0] != 0){
      cout << "Yes" << endl;
    }else {
      cout << "No" << endl;
    }
  }else{
    for(auto v: mp){
      three.push_back(v.first);
    }
    if(mp[three[0]] == mp[three[1]] && mp[three[1]] == mp[three[2]] && (three[0] ^ three[1] ^ three[2]) == 0){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}
