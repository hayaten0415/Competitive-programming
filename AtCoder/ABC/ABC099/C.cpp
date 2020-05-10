#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

//a進法でのnの桁和
int digitsum(int n, int a){
  int res = 0;
  while(n > 0){
    res += n % a;
    n /= a;
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  int ans = n;
  for (int i = 0; i <= n; i++){
    int tmp = digitsum(i, 6) + digitsum(n - i, 9);
    ans = min(ans, tmp);
  }
  cout << ans << endl;
}