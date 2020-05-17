#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  ll sum = 0;
  vector<int> a(n);
  vector<P> bc(m);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  rep(i,m){
    int b;
    ll c;
    cin >> b >> c;
    bc[i] = make_pair(c, b);
  }
  sort(bc.begin(), bc.end(), greater<P>());
  int first_point = 0;
  rep(i,m){
    if(first_point >= n) break;
    rep(j,bc[i].second){
      if(a[first_point] < bc[i].first){
        a[first_point] = bc[i].first;
        first_point++;
      }else {
        break;
      }
    }
  }
  rep(i,n){
    sum += a[i];
  }
  cout << sum << endl;
}