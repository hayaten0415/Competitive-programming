#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  map<int, int> mp;
  rep(i,n){
    int a;
    cin >> a;
    mp[a]++;
  }
  int m;
  cin >> m;
  rep(i,m){
    int b;
    cin >> b;
    if (mp[b] <= 0){
      cout << "NO" << endl;
      return 0;
    }
    mp[b]--;
  }
  cout << "YES" << endl;
}