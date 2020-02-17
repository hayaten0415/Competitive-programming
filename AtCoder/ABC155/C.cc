#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  map<string, int> MA;
  int mx = 0;
  string s;
  rep(i , n){
    cin >> s;
    mx = max(mx, ++MA[s]);
  }
  for (auto ma : MA){
    if(ma.second == mx) cout << ma.first << endl;
  }
}