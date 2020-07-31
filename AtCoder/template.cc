#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;
const int MAX =200000;

void syakutori{
  int right = 0;     
  for (int left = 0; left < n; ++left) {
      while (right < n && (right を 1 個進めたときに条件を満たす)) {
          /* 実際に right を 1 進める */
          // ex: sum += a[right];
          ++right;
      }
      /* break した状態で right は条件を満たす最大なので、何かする */
      // ex: res += (right - left);

      /* left をインクリメントする準備 */
      // ex: if (right == left) ++right;
      // ex: else sum -= a[left];
  }
}

//素因数分解
vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (long long a = 2; a * a <= n; a++){
    if(n % a != 0) continue;
    ll ex = 0; //指数
    while(n % a == 0){
      ex++;
      n /= a;
    }
    res.push_back(make_pair(a, ex));
  }
  if(n != 1){
    res.push_back(make_pair(n, 1));
  }
  return res;
}

//ワーシャルフロイド法
void warshall_floyd(int n) { // nは頂点数
  for (int i = 0; i < n; i++)      // 経由する頂点
    for (int j = 0; j < n; j++)    // 開始頂点
      for (int k = 0; k < n; k++)  // 終端
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
}

//約数列挙 計算量O(sqrt(n))
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

const ll MAX_N = 100000;
ll prime[MAX_N];
bool is_prime[MAX_N + 1];

//エラトステネスの篩
ll sieve(ll n){
  ll p = 0;
  n = MAX_N;
  for (int i = 0; i <= n; i++)
    is_prime[i] = true;
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= n; i++){
    if(is_prime[i]){
      prime[p++] = i;
      for (int j = 2 * i; j <= n; j += i)is_prime[j] = false;
    }
  }
  return p;
}

//繰り返し自乗法(modなし)
ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

ll fac[MAX], finv[MAX], inv[MAX];
// テーブルを作る前処理
// n= 200000までのやつ
void COMinit()
{
  fac[0] = fac[1] = 1;
  finv[0] = finv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < MAX; i++)
  {
    fac[i] = fac[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    finv[i] = finv[i - 1] * inv[i] % MOD;
  }
}

// 二項係数計算
ll COM(int n, int k){
  if (n < k)
    return 0;
  if (n < 0 || k < 0)
    return 0;
  return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

//ある数字nの各桁の和を求める
ll digitsum(ll n) {
  ll res = 0;
  while(n > 0) {
    res += n % 10;
    n /= 10;
  }
  return res;
}

//ユーグリッドの互除法による最大公約数を求めるメソッド
ll gcd(ll a, ll b) {
  ll smaller = min(a, b);
  ll bigger = max(a, b);
  ll surplus = bigger % smaller;
  if (surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}

//最小公倍数を求めるメソッド
ll lcm(ll a, ll b) {
  return a * b / gcd(a, b);
}

//立っているbitの数を返すメソッド
ll Countingbits(long bits){
  bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555);
  bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333);
  bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f);
  bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff);
  return (bits & 0x0000ffff) + (bits >> 16 & 0x0000ffff);
}

//素数判定
bool isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0) {
        // 素数ではない
        return false;
      }
    }
    // 素数である
    return true;
}

int main() {
  return 0;
}