#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

//繰り返し自乗法(modなし)
int mypow(int x, int n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0;
  double coin = 0.5;
  for (int i = 1; i <= n; i++){
    double per = (double)1 / (double)n;
    int v = i;
    int c = 0;
    while(v < k){
      v *= 2;
      c++;
    }
    ans += per * (double)pow(coin, c);
  }
  cout << fixed << setprecision(12) << ans << endl;
}