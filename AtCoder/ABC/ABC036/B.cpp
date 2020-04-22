#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  rep(i,n){
    rep(j,n){
      cout << s[n - 1- j][i];
    }
    cout << endl;
  }
}