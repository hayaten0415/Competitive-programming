#include <bits/stdc++.h>
#include<atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//0-indexedに変換想定
template <typename T>
map<T, int> compress(vector<T> &A, vector<T> &B) {
  int n = A.size();
  map<T, int> mp;
  int cn = 0;
  rep(i, n){
    mp[A[i]] = 0;
    mp[B[i]] = 0;
  }
  for (auto &p : mp){
    p.second = cn;
    cn++;
  }
  return mp;
}

int main(){
  int n;
  ll C;
  cin >> n >> C;
  vector<pair<ll, ll>> event;
  for(ll i = 0; i < n; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    event.emplace_back(a - 1, c);
    event.emplace_back(b, -c);
  }
  sort(event.begin(), event.end());
  ll ans = 0, fee = 0, t = 0;
  for(auto [x, y] : event){
      if(x != t){
          ans += min(C, fee) * (x - t);
          t = x;
      }
      fee += y;
  }
  cout << ans << endl;
}
