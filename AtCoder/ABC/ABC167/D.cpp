#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  ll n;
  ll k;
  cin >> n >> k;
  vector<ll> telepo(n);
  vector<ll> a(n);
  map<ll, ll> mp;
  rep(i, n){
    cin >> a[i];
  }
  telepo[0] = 1;
  for (int i = 0; i < n-1; i++){
    telepo[i + 1] = a[telepo[i]-1];
  }
  ll loop_point = 0;
  ll loop_point_last = 0;
  rep(i,n){
    mp[telepo[i]]++;
    if(mp[telepo[i]] > 1){
      loop_point = i;
      break;
    }
  }
  loop_point_last = loop_point - 1;
  for (ll i = loop_point_last; i >= 0; i--){
    if(telepo[i] == telepo[loop_point]){
      loop_point = i;
      break;
    }
  }
  ll loop_range = loop_point_last - loop_point + 1;
  if (k < loop_point_last){
    cout << telepo[k] << endl;
    return 0;
  }
  k -= loop_point;
  cout << telepo[loop_point + (k % loop_range)] << endl;
}