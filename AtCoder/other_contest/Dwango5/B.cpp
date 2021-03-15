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
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};



int main() {
  int n, k;
  cin >> n >> k;
  int N = (n * (n + 1)) / 2;
  vector<ll> sum;
  vector<ll> A(n);
  vector<ll> OK_set;
  rep(i, n) cin >> A[i];
  rep(i, n){
    ll sum_tmp = A[i];
    sum.emplace_back(sum_tmp);
    for (int j = i + 1; j < n; j++){
      sum_tmp += A[j];
      sum.emplace_back(sum_tmp);
    }
  }
  bool ok = false;
  ll ans = 0;
  int f = 0;
  rrep(j,41){
    int cn_tmp = 0;
    rep(i, N){
      if(sum[i] & (1LL << j))cn_tmp++;
    }
    if(cn_tmp >= k){
      ok = true;
      rep(i, N){
        if(sum[i] & (1LL << j))OK_set.emplace_back(sum[i]);
      }
      ans += (1LL << j);
      f = j;
      break;
    }
  }
  if(!ok){
    cout << 0 << endl;
  }else{
    rrep(j, f){
      int cn_tmp = 0;
      vector<ll> tmp;
      for(auto d : OK_set){
        if(d & (1LL << j)){
          cn_tmp++;
          tmp.emplace_back(d);
        }
      }
      if(cn_tmp >= k){
        swap(OK_set, tmp);
        ans += (1LL << j);
      }
    }
    cout << ans << endl;
  }
}