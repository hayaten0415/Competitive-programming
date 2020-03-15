#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, d;
  int ans = 0;
  int num = 0;
  cin >> n >> d;
  int X[n][d];
  rep(i ,n){
    rep(j, d) {
      cin >> X[i][j];
    }
  }
  rep(i ,n - 1){
    for (int j = i + 1; j < n; j++) {
      rep(k, d) {
        num += pow(X[j][k] - X[i][k], 2);
      }
      for (int m = 1; m <= sqrt(num); m++){
        if(pow(m,2) == num) {
          ans++;
        }
      }
        num = 0;
    }
  }
  cout << ans << endl;
}