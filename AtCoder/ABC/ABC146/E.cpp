#pragma region Macros
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n){
    cin >> A[i];
  }
  vector<ll> sum(n + 1, 0);
  rep(i, n){
    sum[i + 1] = sum[i] + A[i];
  }
  rep(i, n+1){
    sum[i] -= i;
    sum[i] %= k;
    if(sum[i] < 0){
      sum[i] += k;
      sum[i] %= k;
    }
  }
  map<ll, int> mp;
  rep(i, min((int)k, n+1)){
    mp[sum[i]]++;
  }
  ll ans = 0;
  rep(i, n+1){
    ans += (mp[sum[i]] - 1);
    mp[sum[i]]--;
    if(i + k <= n)mp[sum[i+k]]++;
  }
  cout << ans << endl;
}