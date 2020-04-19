#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  string s = "No";
  cin >> a >> b >> c;
  if(a == b && b != c) s = "Yes";
  if(b == c && a != c) s = "Yes";
  if(a == c && a != b) s = "Yes";
  cout << s << endl;
}