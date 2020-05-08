#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  ll ans = 9000000000000000000;
  vector<ll> vx;
  vector<ll> vy;
  vector<pair<ll, ll>> vxy;
  rep(i,n){
    ll x,  y;
    cin >> x >> y;
    vx.push_back(x);
    vy.push_back(y);
    vxy.push_back(make_pair(x, y));
  }
  sort(vx.begin(), vx.end());
  sort(vy.begin(), vy.end());
  for (int xi = 0; xi < n; xi++){
    for (int xj = xi + 1; xj < n; xj++){
      for (int yi = 0; yi < n; yi++){
        for (int yj = yi + 1; yj < n; yj++){
          int cn = 0;
          ll tmp = (ll)(vx[xj] - vx[xi]) * (vy[yj] - vy[yi]);
          for (int i = 0; i < n; i++){
            pair<ll, ll> p = vxy[i];
            if(vx[xi] <= p.first && p.first <= vx[xj] && vy[yi] <= p.second && p.second <= vy[yj]){
              cn++;
            }
            if(cn >= k && ans > tmp){
              ans = tmp;
            }
          }
        }
      }
    }
  }
  cout << ans << endl;
}