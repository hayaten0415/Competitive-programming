#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n;
  cin >> n;
  string ans = "Yes";
  if(n == 1){
    cout << "Yes" << endl;
    return 0;
  }
  vector<int> h(n);
  rep(i, n) {
    cin >> h[i];
  }
  int num = h[0];
  rep(i, n - 1) {
    num = max(num, h[i + 1]);
    if((h[i] > h[i + 1] && h[i] - h[i + 1] > 1) || num - h[i + 1] > 1) {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
}