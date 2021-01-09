#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, k;
  cin >> n >> k;
  ll ma = 0, mb = 0;
  vector<ll> A(n), B(n);
  rep(i, n){
    cin >> A[i];
    chmax(ma, A[i]);
  }
  rep(i, n){
    cin >> B[i];
    chmax(mb, B[i]);
  }
  sort(ALL(B));
  ll left = 1;
  ll right = ma * mb + 1;
  while (right -left > 1){
    ll mid = (left + right) / 2;
    auto ok = [&](ll x) {
      int sum = 0;
      rep(i, n){
        ll num = x / A[i];
        int d = upper_bound(ALL(B), num) - B.begin();
        sum += d;
      }
      return sum < k;
    };
    if(ok(mid)){
      left = mid;
    }else{
      right = mid;
    }
  }
  cout << right << endl;
}