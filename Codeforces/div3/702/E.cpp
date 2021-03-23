#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<long long, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve(){
  int n;
  cin >> n;
  vector<P> A(n);
  vector<ll> sum(n);
  vector<int> ans;
  rep(i, n){
    cin >> A[i].first;
    A[i].second = i;
  }
  sort(ALL(A));
  sum[0] = A[0].first;
  for (int i = 1; i < n; i++){
    sum[i] = sum[i-1] + A[i].first;
  }
  for (int i = n-2; i>= 0; i--){
    if(sum[i] >= A[i+1].first){
      ans.eb(A[i].second + 1);
    }else{
      break;
    }
  }
  ans.eb(A[n-1].second + 1);
  sort(ALL(ans));
  int d = ans.size();
  cout << d << endl;
  rep(i, d){
    cout << ans[i] << (i == d - 1 ? "\n" : " ");
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}