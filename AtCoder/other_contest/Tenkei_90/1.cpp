#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, k;
  ll l;
  cin >> n >> l >> k;
  vector<ll> A;
  A.push_back(0);
  rep(i, n) {
    ll d;
    cin >> d;
    A.push_back(d);
  }
  A.push_back(l);
  auto ok = [&](ll mid) {
    int d = 0;
    ll tmp = 0;
    for (int i = 1; i <= n+1; i++){
      tmp += A[i] - A[i - 1];
      if(tmp >= mid){
        d++;
        tmp = 0;
      }
    }
    return d >=k+1;
  };
  ll left = -1, right = l+1;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    if(ok(mid)){
      left = mid;
    }else{
      right = mid;
    }
  }
  cout << left << endl;
}