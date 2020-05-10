#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int a, b, c, d;
  a = s[0] - '0';
  b = s[1] - '0';
  c = s[2] - '0';
  d = s[3] - '0';
  rep(i,2){
    rep(j,2){
      rep(k,2){
        int num = a;
        if(i == 0) num += b;
        if(i == 1) num -= b;
        if(j == 0) num += c;
        if(j == 1) num -= c;
        if(k == 0) num += d;
        if(k == 1) num -= d;
        if(num == 7){
          cout << a << (i == 0 ? "+" : "-") << b << (j == 0 ? "+" : "-") << c << (k == 0 ? "+" : "-") << d << "=7" << endl;
          return 0;
        }
      }
    }
  }
}
