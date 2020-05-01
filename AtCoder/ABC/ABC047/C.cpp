#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int ans = 0;
  int flag = 0;
  if(s[0] == 'B') flag = 1; 
  rep(i,s.size() - 1){
    char tmp = s[i+1];
    int num = 0;
    if(tmp == 'W') num = 0;
    if(tmp == 'B') num = 1;
    if(flag ^ num){
      ans++;
      flag = num;
    }
  }
  cout << ans << endl;
}