#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int n, m;


int main() {
  cin >> n >> m;
  string s;
  cin >> s;
  int ans = 0;
  int right = 0;
  int cn = 0;
  int left = 0;
  while(left < m) {
    if(s[left] == 'O'){
      right = 0;
      left++;
      continue;
    }
    while(left + right < m && (right % 2 == 0? s[left + right] == 'I': s[left + right] == 'O')){
      cn++;
      right++;
    }
    if(cn < 2 * n + 1){
      left += cn;
      cn = 0;
    }else{
      ans += (cn - 2 * n - 1) / 2 + 1;
      left += cn;
      cn = 0;
    }
    right = 0;
  }
  cout << ans << endl;
}