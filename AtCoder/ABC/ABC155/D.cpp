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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  vector<ll> Plus, Minus,Z;
  rep(i, n) cin >> A[i];
  rep(i,n) {
    if(A[i] > 0)Plus.emplace_back(A[i]);
    else if (A[i] < 0) Minus.emplace_back(abs(A[i]));
    else Z.emplace_back(A[i]);
  }
  ll minus_count = Minus.size();
  ll plus_count = Plus.size();
  ll zero_count = Z.size();
  ll minus_range = minus_count * plus_count;
  ll zero_range = (zero_count * (zero_count - 1)) / 2;
  zero_range += (zero_count) * (plus_count + minus_count);
  if(k > minus_range && k <= zero_range + minus_range){
    cout << 0 << endl;
    return 0;
  }
  sort(ALL(Plus));
  sort(ALL(Minus));
  //答えが0未満になる場合
  if(k <= minus_range){
    ll right = -1;
    ll left = -1000000000000000001;
    auto ok = [&](ll x){
      ll sum = 0;
      rep(i, minus_count){
        ll num = (abs(x) + Minus[i] -1) / Minus[i];
        int d = lower_bound(ALL(Plus), num) - Plus.begin();
        if(plus_count > d)sum += (plus_count - d);
      }
      return sum < k;
    };
    while(right - left > 1){
      ll mid = (left + right) / 2;
      if(ok(mid)){
        left = mid;
      }else{
        right = mid;
      }
    }
    cout << right << endl;
  }else{
    k -= (minus_range + zero_range);
    ll left = 0;
    ll right = 1000000000000000000;
    auto ok2 = [&](ll f){
      ll sum = 0;
      rep(i, minus_count){
        ll num = (f + Minus[i] -1) / Minus[i];
        int d;
        if(f % Minus[i] == 0){
          d = upper_bound(ALL(Minus), num) - Minus.begin();
        }else{
          d = lower_bound(ALL(Minus), num) - Minus.begin();
        }
        d--;
        if(d > i)sum += (d - i);
        else break;
      }
      rep(i, plus_count){
        ll num = (f + Plus[i] -1) / Plus[i];
        int d;
        if(f % Plus[i] == 0){
          d = upper_bound(ALL(Plus), num) - Plus.begin();
        }else{
          d = lower_bound(ALL(Plus), num) - Plus.begin();
        }
        d--;
        if(d > i)sum += (d - i);
        else break;
      }
      return sum < k;
    };
    while(right - left > 1){
      ll mid = (left + right) / 2;
      if(ok2(mid)){
        left = mid;
      }else{
        right = mid;
      }
    }
    cout << right << endl;
  }
}