#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(n== 1){
    cout << "YES" << endl;
    return 0;
  }
  map<int, int> mp;
  rep(i,n){
    int a = s[i] - 'a';
    mp[a]++;
  }
  if(n == 2){
    if(mp.size() == 2){
      cout << "YES" << endl;
      return 0;
    }else {
      cout << "NO" << endl;
      return 0;
    }
  }
  if(mp.size() ==2){
    cout << "NO" << endl;
    return 0;
  }
  ll mn = min(mp[0], min(mp[1], mp[2]));
  mp[0] -= mn;
  mp[1] -= mn;
  mp[2] -= mn;
  if(mp[0] + mp[1] + mp[2] > 2){
    cout << "NO" << endl;
  }else if( mp[0] + mp[1] + mp[2] == 2){
    if(mp[0] == 2 || mp[1] == 2 || mp[2] == 2){
      cout << "NO" << endl;
    }else{
      cout << "YES" << endl;
    }
  }else {
    cout << "YES" << endl;
  }
}