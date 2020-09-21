#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll MAX = (1LL << 60);

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
  ll n;
  cin >> n;
  ll ans = MAX;
  vector<ll> res = divisor(2 * n);
  rep(i, res.size()){
    ll num = (2 * n) / res[i];
    vector<ll> r(2), m(2);
    r[0] = 0, m[0] = res[i];
    r[1] = -1, m[1] = num;
    auto p = atcoder::crt(r, m);
    if (p.first != 0 && p.second != 0) chmin(ans, p.first);
  }
  cout << ans << endl;
}