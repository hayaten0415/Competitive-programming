#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, t;
  cin >> n >> t;
  vector<int> ab(n);
  int sum = 0;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    sum += a;
    ab[i] = a - b;
  }
  int ans = 0;
  sort(ab.begin(), ab.end());
  for (int i = n - 1; i >= 0; i--){
    if(sum <= t)break;
    sum -= ab[i];
    ans++;
  }
  if(sum > t){
    cout << -1 << endl;
  }else{
    cout << ans << endl;
  }
}