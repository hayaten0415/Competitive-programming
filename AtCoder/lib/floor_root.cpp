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


uint64_t floor_root(uint64_t a, uint64_t k) {
    if(a <= 1 or k == 1) return a;
    if(k >= 64) return 1;
    if(k == 2) return sqrtl(a);
    if(a == uint64_t(-1)) a--;
    auto p = [](uint64_t x, uint64_t y) {
        auto mul = [](const uint64_t &x, const uint64_t &y) {
            if(x < UINT_MAX and y < UINT_MAX) return x * y;
            if(x == uint64_t(-1) or y == uint64_t(-1)) return uint64_t(-1);
            return (x <= uint64_t(-1) / y ? x * y : uint64_t(-1));
        };
        if(y == 0) return 1ULL;
        auto res = 1ULL;
        while(y) {
            if(y & 1) res = mul(res, x);
            x = mul(x, x);
            y >>= 1;
        }
        return res;
    };
    uint64_t res = (k == 3 ? cbrt(a) - 1 : pow(a, nextafter(1 / double(k), 0)));
    while(p(res + 1, k) <= a) res++;
    return res;
}

int main() {

}