#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  int n;
  cin >> s >> n;
  int a = (n - 1) / 5;
  int b = (n -1) % 5;
  cout << s[a] << s[b] << endl;
}


