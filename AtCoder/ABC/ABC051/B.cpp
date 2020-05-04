#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int k, s;
  int ans = 0;
  cin >> k >> s;
  for (int i = 0; i<= k; i++){
    for (int j = 0; j <= k; j++){
      if(i + j > s || s - i - j > k ) continue;
      ans++;
    }
  }
  cout << ans << endl;
}