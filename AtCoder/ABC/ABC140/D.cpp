#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ans = 0;
  rep(i, n-1){
    if(s[i] == s[i+1]) ans++;
  }
  ans += 2 * k;
  cout << min(ans, n - 1) << endl;

}