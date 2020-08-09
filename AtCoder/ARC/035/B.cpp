#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 1000000007;
const int MAX =20000;

ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
// n= 200000までのやつ
void COMinit(){
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++){
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

int main() {
  int n;
  cin >> n;
  COMinit();
  vector<ll> a(n), sum(n + 1, 0), cnt(10001,0);
  rep(i, n){
    cin >> a[i];
    cnt[a[i]]++;
  }
  sort(ALL(a));
  ll ans_sum = 0;
  ll ans_count = 1;
  rep(i, n){
    sum[i+1] = sum[i] + a[i];
    ans_sum += sum[i+1];
  }
  rep(i,10001){
    ans_count *= fac[cnt[i]];
    ans_count %= MOD;
  }
  cout << ans_sum << endl;
  cout << ans_count << endl;
}

        