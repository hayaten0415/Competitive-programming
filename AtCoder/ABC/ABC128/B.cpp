#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  pair<pair<string, int>, int> V[n];
  rep(i,n){
    string s;
    int k;
    cin >> s >> k;
    V[i] = make_pair(make_pair(s, -k), i);
  }
  sort(V, V + n);
  rep(i,n){
    cout << V[i].second + 1 << endl;
  }
  return 0;
}