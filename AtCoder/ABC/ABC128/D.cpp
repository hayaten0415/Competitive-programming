#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;



int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  int ans = 0;
  rep(i, n) cin >> v[i];
  for (int a = 0; a <= min(n, k); a++){
    for (int b = 0; a + b <= min(n, k); b++){
      vector<int> tmp;
      int cur = 0;
      for (int i = 0; i < a; i++) tmp.push_back(v[i]), cur+= v[i];
      for (int i = 0; i < b; i++) tmp.push_back(v[n - i -1]), cur += v[n - 1 -i];
      sort(tmp.begin(), tmp.end());
      for (int i = 0; i < min((int)tmp.size(), k - a - b); i++){
        if(tmp[i] < 0) cur -= tmp[i];
      }
      ans = max(ans, cur);
    }
  }
  cout << ans << endl;
}