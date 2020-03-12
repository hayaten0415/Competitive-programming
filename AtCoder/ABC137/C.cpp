#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  ll ans = 0;
  cin >> n;
  vector<string> a(n);
  unordered_map<string, int> b;
  string s;
  rep(i,n) {
    cin >> s;
    sort(s.begin(), s.end());
    a[i] = s;
    //キーがすでに含まれていればインクリメント
    if (b.find(s) != b.end()) {
      b.at(s)++;
      ans += b.at(s) - 1;
    //キーが含まれていなければ新たにキーを入れて値は1に設定
    } else {
      b[s] = 1;
    }
  }
  cout << ans << endl;
}