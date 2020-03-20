#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n, num;
  int ans = 1000000;
  cin >> n;
  vector<int> W(n + 1);
  W[0] = 0;
  for (int i = 1; i < n + 1; i++){
    cin >> num;
    W[i] = W[i - 1] + num;
  }
  rep(i ,n + 1){
    ans = min(ans, abs((W[n] - W[i]) - W[i]));
  }
  cout << ans << endl;
}