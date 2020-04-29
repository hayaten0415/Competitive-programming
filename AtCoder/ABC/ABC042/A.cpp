#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  map<int, int> mp;
  rep(i,3){
    int tmp;
    cin >> tmp;
    mp[tmp]++;
  }
  if(mp[5] == 2 && mp[7] == 1){
    cout << "YES" << endl;
  }else {
    cout << "NO" << endl;
  }
}