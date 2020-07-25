#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  for (int i = 0; i < n - k; i++){
    if(a[i] < a[i+ k]){
      cout << "Yes" << endl;
    }else{
      cout << "No" << endl;
    }
  }
}