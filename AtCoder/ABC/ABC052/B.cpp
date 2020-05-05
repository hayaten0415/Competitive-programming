#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  int num = 0;
  rep(i,n){
    if(s[i] == 'I')num++;
    else num--;
    ans = max(ans, num);
  }
  cout << ans << endl;
}