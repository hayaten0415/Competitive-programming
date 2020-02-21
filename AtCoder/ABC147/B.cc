#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  int i = 0;
  int count = 0;
  cin >> s;
  while (i < s.length() - i - 1){
    if(s[i] != s[s.length() - 1 - i]) count++;
    i++;
  }
  cout << count << endl;
}