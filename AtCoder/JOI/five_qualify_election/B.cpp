#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n;
  unordered_map<string, string> mp;
  rep(i, n) {
    string a, b;
    cin >> a >> b;
    mp[a] = b;
  }
  cin >> m;
  string ans = "";
  rep(i, m) {
    string a;
    cin >> a;
    if(mp.find(a) == mp.end()){
      ans += a;
    }else{
      ans += mp[a];
    }
  }
  cout << ans << endl;
}