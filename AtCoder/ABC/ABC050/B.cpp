#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int sum = 0;
  vector<int> T(n);
  rep(i,n){
    cin >> T[i];
    sum += T[i];
  }
  int m;
  cin >> m;
  rep(i,m){
    int p, x;
    cin >> p >> x;
    p--;
    int ans = sum - T[p] + x;
    cout << ans << endl;
  }
}