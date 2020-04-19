#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  int ans = 0;
  cin >> n;
  vector<int> a(n);
  rep(i ,n){
    cin >> a[i];
  }
  rep(i ,n -2){
    if((a[i] < a[i + 1] && a[i + 1] < a[i + 2]) || (a[i] > a[i + 1] && a[i + 1] > a[i + 2])){
      ans++;
    }
  }
  cout << ans << endl;
}