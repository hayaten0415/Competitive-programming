#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  int k;
  cin >> s >> k;
  int n = s.size();
  if(n == 1){
    int rest = k % 26;
    int g = s[0] - 'a';
    g += rest;
    g %= 26;
    s[0] = g + 'a';
    cout << s << endl;
    return 0;
  }
  rep(i, n){
    int a = s[i] - 'a';
    if(a == 0)continue;
    if(26 - a <= k){
      s[i] = 'a';
      k -= 26 - a;
    }
  }
  if(k > 0){
    int rest = k % 26;
    int g = s[n-1] - 'a';
    g += rest;
    g %= 26;
    s[n-1] = g + 'a';
  }
  cout << s << endl;
}