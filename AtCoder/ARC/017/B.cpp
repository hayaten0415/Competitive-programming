#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> b(n, 0);
  rep(i, n) cin >> a[i];
  if(k == 1) {
    cout << n << endl;
    return 0;
  }
  for(int i = 0; i < n-1; i++){
    if(a[i] < a[i+1]){
      b[i+1] = b[i] + 1;
    }else{
      b[i+1] = b[i];
    }
  }
  int ans = 0;
  for (int i = k - 1; i < n; i++){
    if(b[i] - b[i-k+1] == k-1)ans++;
  }
  cout << ans  << endl;
}