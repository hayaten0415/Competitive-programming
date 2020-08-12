#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  ll ans1 = 0, ans2 = 0;
  rep(i, n){
    if(i % 2 == 0 && s[i] == '0')ans1++;
    if(i % 2 == 0 && s[i] == '1')ans2++;
    if(i % 2 == 1 && s[i] == '1')ans1++;
    if(i % 2 == 1 && s[i] == '0')ans2++;
  }
  cout << min(ans1, ans2) << endl;
}