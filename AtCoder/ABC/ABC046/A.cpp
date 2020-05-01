#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  map<int, int> mp;
  mp[a]++;
  mp[b]++;
  mp[c]++;
  cout << mp.size() << endl;
}