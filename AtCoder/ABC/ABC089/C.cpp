#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> res(5, 0);
  rep(i,n){
    string s;
    cin >> s;
    if(s[0] == 'M') res[0]++;
    if(s[0] == 'A') res[1]++;
    if(s[0] == 'R') res[2]++;
    if(s[0] == 'C') res[3]++;
    if(s[0] == 'H') res[4]++;
  }
  ll ans = 0;
  for (int i = 0; i < 5; i++){
    for (int j = i + 1; j < 5; j++){
      for (int k = j + 1; k < 5; k++){
        ans += res[i] * res[j] * res[k];
      }
    }
  }
  cout << ans << endl;
}