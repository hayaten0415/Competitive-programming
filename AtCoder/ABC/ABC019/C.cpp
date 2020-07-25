#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  set<ll> st;
  int ans = 0;
  rep(i, n){
    while(a[i] % 2 == 0){
      a[i] /= 2;
    }
    if(st.find(a[i]) == st.end()){
      ans++;
      st.insert(a[i]);
    }
  }
  cout << ans << endl;
}