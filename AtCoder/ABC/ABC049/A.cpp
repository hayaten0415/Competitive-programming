#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  string ans = "consonant";
  if(s == "a" || s == "i" || s == "u" || s == "e" || s == "o"){
    ans = "vowel";
  }
  cout << ans << endl;
}