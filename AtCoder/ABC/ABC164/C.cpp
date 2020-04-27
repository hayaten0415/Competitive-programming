#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  map<string, int> mp;
  rep(i,n){
    string s;
    cin >> s;
    mp[s]++;
  }
  cout << mp.size() << endl;
}