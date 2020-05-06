#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  ll W;
  cin >> n >> W;
  vector<ll> w(n);
  vector<ll> v(n);
  rep(i, n) cin >> w[i] >> v[i];
  ll min_weight = w[0];
  vector<ll> min_weight_value1;
  vector<ll> min_weight_value2;
  vector<ll> min_weight_value3;
  vector<ll> min_weight_value4;
  rep(i,n){
    if(w[i] == w[0]) min_weight_value1.push_back(v[i]);
    if(w[i] == w[0] + 1) min_weight_value2.push_back(v[i]);
    if(w[i] == w[0] + 2) min_weight_value3.push_back(v[i]);
    if (w[i] == w[0] + 3) min_weight_value4.push_back(v[i]);
  }
  sort(min_weight_value1.begin(), min_weight_value1.end(), greater<ll>());
  sort(min_weight_value2.begin(), min_weight_value2.end(), greater<ll>());
  sort(min_weight_value3.begin(), min_weight_value3.end(), greater<ll>());
  sort(min_weight_value4.begin(), min_weight_value4.end(), greater<ll>());
  ll weight1 = w[0];
  ll weight2 = w[0] + 1;
  ll weight3 = w[0] + 2;
  ll weight4 = w[0] + 3;
  vector<ll> sum1(min_weight_value1.size() + 1, 0);
  vector<ll> sum2(min_weight_value2.size() + 1, 0);
  vector<ll> sum3(min_weight_value3.size() + 1, 0);
  vector<ll> sum4(min_weight_value4.size() + 1, 0);
  for (int i = 1; i <= min_weight_value1.size(); i++) sum1[i] = sum1[i-1] + min_weight_value1[i-1];
  for (int i = 1; i <= min_weight_value2.size(); i++) sum2[i] = sum2[i-1] + min_weight_value2[i-1];
  for (int i = 1; i <= min_weight_value3.size(); i++) sum3[i] = sum3[i-1] + min_weight_value3[i-1];
  for (int i = 1; i <= min_weight_value4.size(); i++) sum4[i] = sum4[i-1] + min_weight_value4[i-1];
  ll ans = 0;
  rep(i,sum1.size()){
    rep(j,sum2.size()){
      rep(k,sum3.size()){
        rep(m, sum4.size()){
          if(weight1 * i + weight2 * j + weight3 * k + weight4 * m <= W){
            ans = max(ans, sum1[i] + sum2[j] + sum3[k] + sum4[m]);
          }
        }
      }
    }
  }
  cout << ans << endl;
}