#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> res(26, 0);
  rep(i, n){
    string s;
    cin >> s;
    vector<ll> tmp(26, 0);
    rep(j, s.size()){
      ll num = s.at(j) - 'a';
      tmp[num]++;
    }
    rep(k,26){
      if(i > 0){
        res.at(k) = min(res.at(k), tmp.at(k));
      }else {
        res.at(k) = tmp.at(k);
      }
    }
  }
  rep(i, 26){
    rep(j, res.at(i)){
      char ch =  'a' + i;
      cout << ch;
    }
  }
  cout << endl;
}