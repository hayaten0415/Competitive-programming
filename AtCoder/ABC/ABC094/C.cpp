#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i,n){
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b.begin(), b.end());
  ll bigger = b[n / 2];
  ll smaller = b[n / 2 - 1];
  rep(i, n){
    if(a[i] <= smaller){
      cout << bigger << endl;
    }else{
      cout << smaller << endl;
    }
  }
}