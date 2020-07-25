#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll dp[81][20000][3];

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  ll num = 1000;
  for (int i = 0; i < n-1; i++){
    ll stock = 0;
    if(a[i] < a[i+1]) stock = num / a[i];
    num += (a[i+ 1] - a[i]) * stock; 
  }
  cout << num << endl;
}