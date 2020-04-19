#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  int ans = 0;
  cin >> n;
  for (int i = 1; i <= n; i++){
    string s = to_string(i);
    if(s.size() % 2 == 1) {
      ans++;
    }
  }
  cout << ans << endl;
}