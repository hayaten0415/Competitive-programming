#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

vector<int> res(101, 0);

//素因数分解
void prime_factorize(int n) {
  for (int a = 2; a * a <= n; a++){
    if(n % a != 0) continue;
    while(n % a == 0){
      res[a]++;
      n /= a;
    }
  }
  if(n != 1){
    res[n]++;
  }
  return;
}

int main() {
  int n;
  cin >> n;
  int ans = 0;
  map<int, int> mp;
  for (int i = 2; i <= n; i++){
    prime_factorize(i);
  }
  for (int i = 2; i <= n; i++){
    if(res[i] >=2) mp[3]++;
    if(res[i] >= 4)mp[5]++;
    if(res[i] >= 14)mp[15]++;
    if(res[i] >= 24)mp[25]++;
    if(res[i] >= 74)mp[75]++;
  }
  ans += mp[75];
  ans += mp[25] * (mp[3]-1);
  ans += mp[15] * (mp[5] -1);
  ans += ((mp[5] * (mp[5] - 1)) / 2) * (mp[3]-2);
  cout << ans << endl;
}
