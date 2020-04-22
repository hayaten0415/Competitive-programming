#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n, c = 0;
  cin >> n;
  vector<int> a(n);
  map<int, int> m;
  rep(i, n){
    cin >> a[i], m[a[i]];
  }
  for (auto &i:m){
    i.second = c;
    c++;
  }
  rep(i, n) cout << m[a[i]] << endl;
}