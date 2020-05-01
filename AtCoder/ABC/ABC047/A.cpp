#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  string ans = "No";
  if(a+b == c) ans = "Yes";
  if(b+c == a) ans = "Yes";
  if(c+a == b) ans = "Yes";
  cout << ans << endl;
}