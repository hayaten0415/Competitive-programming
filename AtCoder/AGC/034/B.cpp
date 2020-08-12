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
  int a_count = 0;
  ll ans = 0;
  rep(i, n-2){
    if(s[i] == 'A' && s[i+1] == 'B' && s[i+2] == 'C'){ 
      ans += a_count + 1;
      s[i+2] = 'A';
      i++;
    }else if(s[i] == 'A'){ 
      a_count++;
    }else { 
      a_count = 0;
    }
  }
  cout << ans << endl;
}