#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> res(n);
  for (int i = 1; i <= 100; i++){
    for (int j = 1; j <= 100; j++){
      for (int k = 1; k <= 100; k++){
        ll ans = i * i + j * j + k * k;
        ans += i * j + j * k + k * i;
        if(ans <= n) res[ans-1]++;
      }
    }
  }
  rep(i, n){
    cout << res[i] << endl;
  }
}