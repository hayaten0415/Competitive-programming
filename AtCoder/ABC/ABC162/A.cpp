#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  bool cond = false;
  if(s[0] == '7') cond = true; 
  if (s[1] == '7') cond = true;
  if (s[2] == '7') cond = true;
  cout << (cond ? "Yes" : "No") << endl;
}