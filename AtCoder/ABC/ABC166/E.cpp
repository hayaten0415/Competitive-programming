#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  map<int, int> mp;
  ll ans = 0;
  rep(i,n){
    int aj = i - A[i];
    ans += mp[aj];
    int ai = A[i] + i;
    mp[ai]++;
  }
  cout << ans << endl;
}