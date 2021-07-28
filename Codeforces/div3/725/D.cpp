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

vector<P> prime_factorize(int n) {
  vector<P> res;
  for (int a = 2; a * a <= n; a++){
    if(n % a != 0) continue;
    int ex = 0; //指数
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

vector<int> divisor(int n) {
    vector<int> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

void solve() {
  int a, b;
  int k;
  cin >> a >> b >> k;
  int d = gcd(a, b);
  if(a == 1 && b == 1){
    cout << "NO" << endl;
    return;
  }
  int a1 = a / d;
  int b1 = b / d;
  vector<P> A = prime_factorize(a1);
  vector<P> B = prime_factorize(b1);
  vector<P> C = prime_factorize(d);
  int res1 = 0, res2 = 0, res3 = 0;
  for(auto [e, f] : A){
    res1 += f;
  }
  for(auto [e, f] : B){
    res2 += f;
  }
  for(auto [e, f] : C){
    res3 += f;
  }
  int mx = res1 + res2 + res3 *2;
  int mn = 2;
  if(d == a || d == b)mn = 1;
  if(a==b)mn = 2;
  if(mn <= k && mx >= k){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}