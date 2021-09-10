#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;
// referece: https://37zigen.com/linear-sieve/
class LinearSieve {
    public:
        LinearSieve(unsigned int n) : _n(n), min_prime_factor(std::vector<unsigned int>(n + 1)) {
            std::iota(min_prime_factor.begin(), min_prime_factor.end(), 0);
            prime_list.reserve(_n + 1);
            for (unsigned int d = 2; d <= _n; ++d) {
                if (min_prime_factor[d] == d) {
                    prime_list.push_back(d);
                }
                unsigned int prime_max = std::min(min_prime_factor[d], _n / d);
                for (unsigned int prime : prime_list) {
                    if (prime > prime_max) {
                        break;
                    }
                    min_prime_factor[prime * d] = prime;
                }
            }
        }
        unsigned int prime_num() const {
            return prime_list.size();
        }
        const std::vector<unsigned int>& get_prime_list() const {
            return prime_list;
        }
        const std::vector<unsigned int>& get_min_prime_factor() const {
            return min_prime_factor;
        }
    private:
        const unsigned int _n;
        std::vector<unsigned int> min_prime_factor;
        std::vector<unsigned int> prime_list;
};

template <typename mint>
class ArbitraryModBinomialCoefficients {
    public:
        ArbitraryModBinomialCoefficients(unsigned int N) :
            _N(N), _M(mint::mod()), _sieve(LinearSieve(N)), _binom(std::vector<mint>(N + 1)) {
            solve();
        }
        mint operator[](unsigned int k) const {
            return _binom[k];
        }
        const std::vector<mint>& get_coeffs() const {
            return _binom;
        }
        const LinearSieve& get_sieve() const {
            return _sieve;
        }
    private:
        const unsigned int _N, _M;
        const LinearSieve _sieve;
        std::vector<mint> _binom;
 
        void mod_invs(std::vector<mint>& invs) {
            auto &mpf = _sieve.get_min_prime_factor();
            if (_N >= 1) invs[1] = 1;
            for (unsigned int i = 2; i <= _N; ++i) {
                unsigned int pf = mpf[i];
                if (pf == i) {
                    if (_M % pf) invs[i] = mint(i).inv();
                } else {
                    invs[i] = invs[pf] * invs[i / pf];
                }
            }
        }
 
        void solve() {
            auto &primes = _sieve.get_prime_list();
            std::vector<unsigned int> d(_N + 1, 0);
            std::vector<unsigned int> p;
            for (unsigned int prime : primes) {
                if (_M % prime) continue;
                p.push_back(prime);
                unsigned int sz = p.size();
                for (unsigned int v = prime; v <= _N; v += prime) {
                    d[v] = sz;
                }
            }
            const unsigned int L = p.size();
            p.insert(p.begin(), 0);
            std::vector<mint> invs(_N + 1);
            mod_invs(invs);
            std::vector<std::vector<mint>> powers(L + 1);
            for (unsigned int i = 1; i <= L; ++i) {
                unsigned int max_index = _N / (p[i] - 1);
                powers[i].resize(max_index + 1);
                mint pi = p[i];
                powers[i][0] = 1;
                for (unsigned int j = 0; j < max_index; ++j) {
                    powers[i][j + 1] = powers[i][j] * pi;
                }
            }
            const unsigned int half = (_N + 1) / 2;
            mint S = 1;
            std::vector<unsigned int> T(L, 0);
            _binom[0] = 1;
            for (unsigned int k = 1; k <= half; ++k) {
                unsigned int num = _N - k + 1, den = k;
                while (d[num]) ++T[d[num]], num /= p[d[num]];
                while (d[den]) --T[d[den]], den /= p[d[den]];
                S *= num * invs[den];
                _binom[k] = S;
                for (unsigned int i = 1; i <= L; ++i) {
                    _binom[k] *= powers[i][T[i]];
                }
            }
            for (unsigned int k = half + 1; k <= _N; ++k) {
                _binom[k] = _binom[_N - k];
            }
        }
};
using mint = atcoder::modint;

int main() {
  int n, q, m;
  cin >> q >> n >> m;
  mint::set_mod(m);
  ArbitraryModBinomialCoefficients<mint> binoms(n);
  mint ans = 1;
  while(q--){
    int x,y;
    cin >> x >> y;
    int r1 = abs(x+y), r2 = abs(x-y);
    if(r1 > n || r2 > n || (r1%2)!=(n%2) ||(r2%2)!=(n%2)){
      cout << 0 << endl;
      return 0;
    }
    ans *= binoms[n] * binoms[(n - r1) / 2];
    ans *= binoms[n] * binoms[(n - r2) / 2];
  }
  cout << ans.val() << endl;
}