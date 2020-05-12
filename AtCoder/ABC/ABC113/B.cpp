#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  double num = 0.006;
  int n, t, a;
  cin >> n >> t >> a;
  int ans = 0;
  double diff = 100000000.00;
  rep(i,n){
    int h;
    cin >> h;
    double num2 = (double)t - h * num;
    double diff_1 = abs(num2 - (double)a);
    if(diff_1 < diff){
      diff = diff_1;
      ans = i + 1;
    }
  }
  cout << ans << endl;
}