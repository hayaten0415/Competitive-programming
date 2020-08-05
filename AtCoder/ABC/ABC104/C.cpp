#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int d;
  ll g;
  cin >> d >> g;
  vector<ll> p(d);
  vector<ll> c(d);
  rep(i, d) cin >> p[i] >> c[i];
  ll ans = 1000;
  for (int bit = 0; bit < (1 << d); bit++){
    vector<bool> bonus_valid(d,false);
    ll sum_score = 0;
    ll problems = 0;
    rep(i, d){
      if(bit & (1 << i)){
        problems += p[i];
        bonus_valid[i] = true;
        sum_score += 100 * (i + 1) *  p[i] + c[i];
      }
    }
    if(sum_score >= g){
      ans = min(ans, problems);
      continue;
    }else{
      ll rest = g - sum_score;
      bool out = false;
      rrep(i, d){
        if(!bonus_valid[i]){
          ll plus = rest / (100 * (i + 1));
          if(rest % (100 * (i + 1)) != 0)plus++;
          if(plus >= p[i]) out = true;
          else{
            problems += plus;
            break;
          }
        }
      }
      if(out)continue;
      ans = min(ans, problems);
    }
  }
  cout << ans << endl;
}