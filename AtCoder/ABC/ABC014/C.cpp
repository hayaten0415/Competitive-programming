#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> sum(1000002, 0);
  rep(i,n){
    int a, b;
    cin >> a >> b;
    sum[a]++, sum[b + 1]--;
  }
  int ans = sum[0];
  rep(i, 1000001){
    sum[i + 1] += sum[i];
    ans = max(ans, sum[i + 1]);
  }
  cout << ans << endl;
}