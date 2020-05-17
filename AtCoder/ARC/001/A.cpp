#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;
  ll sum = 0;
  rep(i,n){
    if(s[i] =='A')sum += 4;
    if(s[i] == 'B')sum += 3;
    if(s[i] == 'C')sum += 2;
    if(s[i] == 'D')sum += 1;
  }
  double ans = (double)sum / (double)n;
  cout << fixed << setprecision(12) << ans << endl;
}