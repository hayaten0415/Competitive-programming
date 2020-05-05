#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  map<int, int> mp;
  rep(i, n) cin >> a[i];
  rep(i, n){
    mp[a[i]]++;
  }
  if(mp.size() % 2 == 0){
    cout << mp.size() - 1 << endl;
  }else {
    cout << mp.size() << endl;
  }
}