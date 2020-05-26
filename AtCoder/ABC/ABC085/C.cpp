#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, y;
  cin >> n >> y;
  for (int i = 0; i <= n; i++){
    for (int k = 0; i + k <= n; k++){
      if(1000 * i + 5000 * k + (n - i - k) * 10000 > y) continue;
      if (1000 * i + 5000 * k + (n - i - k) * 10000 == y){
        cout << n - i - k << " " << k << " " << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}