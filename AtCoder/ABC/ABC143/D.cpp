#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll ans = 0;
  vector<int> L(n);
  rep(i, n) cin >> L[i];
  sort(L.begin(), L.end());
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      int left = j;
      int right = n;
      while(right - left > 1){
        int mid = (left + right) / 2;
        if(L[mid] < L[i] + L[j]){
          left = mid;
        }else {
          right = mid;
        }
      }
      ans += left - j;
    }
  }
  cout << ans << endl;
}