#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
vector<ll> A(19);

ll dfs(ll mid){
  if(mid < 10){
    return (mid * (mid + 1LL)) / 2LL;
  }
  ll res = 0;
  ll add = 0;
  ll d = 1;
  for(ll i = 1; i <= 1e17; i*= 10LL){
    ll mx = min(i * 10-1, mid);
    ll cn = mx- i + 1;
    res += cn * add;
    res += (cn * (cn + 1)) / 2LL * (d);
    add += cn * d;
    d++;
    if(mx == mid)break;
  }
  return res;
}

ll dfs2(ll mid){
  if(mid < 10)return mid;
  ll res = 0;
  ll a = upper_bound(ALL(A), mid) - A.begin();
  a--;
  ll b = (mid - A[a] + 1);
  res += b * (a + 1);
  while(a > 1){
    res += (A[a] - A[a-1]) * a;
    a--;
  }
  res += 9;
  return res;
}

void solve() {
  ll n;
  cin >> n;
  A[0] = 1;
  rep(i, 18) A[i + 1] = A[i] * 10LL;
  ll left = 0, right = 1e9;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    if(dfs(mid) >= n){
      right = mid;
    }else{
      left = mid;
    }
  }
  n -= dfs(left);
  //cout << right << endl;
  left = 0;
  while(right - left > 1){
    ll mid = (left + right) / 2;
    if(dfs2(mid) >= n){
      right = mid;
    }else{
      left = mid;
    }
  }
  n -= dfs2(left);
  string res = to_string(right);
  cout << res[n - 1] << endl;
  //cout << dfs(100) << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}