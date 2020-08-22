#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  ll num = 0;
  rep(i, n){
    num += s[i] - '0';
  }
  if(num % 9 == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}