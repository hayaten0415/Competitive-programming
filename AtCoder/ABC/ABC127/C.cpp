#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  int ans = 0;
  vector<int> c(n + 1, 0);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--;
    c[a]++, c[b]--;
  }
  rep(i, n){
    c[i + 1] += c[i];
  }
  rep(i, n){
    if(c[i] == m)ans++;
  }
  cout << ans << endl;
}