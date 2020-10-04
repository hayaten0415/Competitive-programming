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

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
  int n,k;
  cin >> n >> k;
  vector<ll> A(n);
  ll sum = 0;
  ll mx = 0;
  rep(i, n){
    cin >> A[i];
    sum += A[i];
    mx = max(mx, A[i]);
  }
  vector<ll> div = divisor(sum);
  ll ans = 1;
  for(int i = 0; i < div.size(); i++){
    int sz = 0;
    ll g = div[i];
    ll cn = 0;
    vector<ll> tmp;
    rep(i, n){
      ll num = A[i] % g;
      if(num != 0){
        tmp.emplace_back(num);
        sz++;
      }
    }
    sort(ALL(tmp));
    vector<ll> minus(sz, 0), plus(sz, 0);
    rep(i, sz){
      if(i == 0){
        minus[i] = tmp[i];
        plus[sz - 1 - i] = g - tmp[sz - 1 - i];
      }else{
        minus[i] = minus[i - 1] + tmp[i];
        plus[sz - 1 - i] = plus[sz - i] + (g-tmp[sz - 1 - i]);
      }
    }
    rep(i, sz-1){
      if(minus[i]== plus[i+1]){
        cn = minus[i];
        break;
      }
    }
    if(cn <= k){
      ans = max(ans, g);
    }
  }
  cout << ans << endl;
}