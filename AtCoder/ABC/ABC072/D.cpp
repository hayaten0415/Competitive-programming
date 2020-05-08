#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int j = 0;
  while(true){
    if(j >= n) break;
    if(a[j] == j+1){
      ans++;
      if(a[j +1] == j+2) j += 2;
      else j++;
    }else {
      j++;
    }
  }
  cout << ans << endl;
}