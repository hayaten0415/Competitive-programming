#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#pragma GCC optimize("unroll-loops")
using namespace std;
//#include<boost/multiprecision/cpp_int.hpp>
//#include<boost/multiprecision/cpp_dec_float.hpp>
//namespace mp=boost::multiprecision;
//#define mulint mp::cpp_int
//#define mulfloat mp::cpp_dec_float_100
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define INF (1<<30)
#define LINF (lint)(1LL<<56)
#define endl "\n"
#define rep(i,n) for(lint (i)=0;(i)<(n);(i)++)
#define reprev(i,n) for(lint (i)=(n-1);(i)>=0;(i)--)
#define flc(x) __builtin_popcountll(x)
#define pint pair<int,int>
#define pdouble pair<double,double>
#define plint pair<lint,lint>
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define vec vector<lint>
#define nep(x) next_permutation(all(x))
typedef long long lint;
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
const int MAX_N=3e5+5;
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return 1;}return 0;}
//vector<int> bucket[MAX_N/1000];
//constexpr int MOD=1000000007;
constexpr int MOD=998244353;
#include<atcoder/all>
using namespace atcoder;
typedef __int128_t llint;

struct SuccinctIndexableDictionary {
    size_t length;
    size_t blocks;
    vector< unsigned > bit, sum;

    SuccinctIndexableDictionary() {
    }

    SuccinctIndexableDictionary(size_t _length) {
        length = _length;
        blocks = (length + 31) >> 5;
        bit.assign(blocks, 0U);
        sum.assign(blocks, 0U);
    }

    void set(int k) {
        bit[k >> 5] |= 1U << (k & 31);
    }

    void build() {
        sum[0] = 0U;
        for(int i = 1; i < blocks; i++) {
            sum[i] = sum[i - 1] + __builtin_popcount(bit[i - 1]);
        }
    }

    bool operator[](int k) const {
        return (bool((bit[k >> 5] >> (k & 31)) & 1));
    }

    int rank(int k) {
        return (sum[k >> 5] + __builtin_popcount(bit[k >> 5] & ((1U << (k & 31)) - 1)));
    }

    int rank(bool val, int k) {
        return (val ? rank(k) : k - rank(k));
    }

    int select(bool val, int k) {
        if(k < 0 || rank(val, length) <= k) return (-1);
        int low = 0, high = length;
        while(high - low > 1) {
            int mid = (low + high) >> 1;
            if(rank(val, mid) >= k + 1) high = mid;
            else low = mid;
        }
        return (high - 1);
    }

    int select(bool val, int i, int l) {
        return select(val, i + rank(val, l));
    }
};

template< typename T, int MAXLOG >
struct WaveletMatrix {
    size_t length;
    SuccinctIndexableDictionary matrix[MAXLOG];
    int mid[MAXLOG];

    WaveletMatrix() = default;

    WaveletMatrix(vector< T > v) : length(v.size()) {
        vector< T > l(length), r(length);
        for(int level = MAXLOG - 1; level >= 0; level--) {
            matrix[level] = SuccinctIndexableDictionary(length + 1);
            int left = 0, right = 0;
            for(int i = 0; i < length; i++) {
                if(((v[i] >> level) & 1)) {
                matrix[level].set(i);
                r[right++] = v[i];
                }
                else {
                l[left++] = v[i];
                }
            }
            mid[level] = left;
            matrix[level].build();
            v.swap(l);
            for(int i = 0; i < right; i++) {
                v[left + i] = r[i];
            }
        }
    }

    pair< int, int > succ(bool f, int l, int r, int level) {
        return {matrix[level].rank(f, l) + mid[level] * f, matrix[level].rank(f, r) + mid[level] * f};
    }

    // v[k]
    T access(int k) {
        T ret = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            bool f = matrix[level][k];
            if(f) ret |= T(1) << level;
            k = matrix[level].rank(f, k) + mid[level] * f;
        }
        return ret;
    }

    T operator[](const int &k) {
        return access(k);
    }

    // count i s.t. (0 <= i < r) && v[i] == x
    int rank(const T &x, int r) {
        int l = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            tie(l, r) = succ((x >> level) & 1, l, r, level);
        }
        return r - l;
    }

    // k-th(0-indexed) smallest number in v[l,r)
    T kth_smallest(int l, int r, int k) {
        assert(0 <= k && k < r - l);
        T ret = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            int cnt = matrix[level].rank(false, r) - matrix[level].rank(false, l);
            bool f = cnt <= k;
            if(f) {
                ret |= T(1) << level;
                k -= cnt;
            }
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // k-th(0-indexed) largest number in v[l,r)
    T kth_largest(int l, int r, int k) {
        return kth_smallest(l, r, r - l - k - 1);
    }

    // count i s.t. (l <= i < r) && (v[i] < upper)
    int range_freq(int l, int r, T upper) {
        int ret = 0;
        for(int level = MAXLOG - 1; level >= 0; level--) {
            bool f = ((upper >> level) & 1);
            if(f) ret += matrix[level].rank(false, r) - matrix[level].rank(false, l);
            tie(l, r) = succ(f, l, r, level);
        }
        return ret;
    }

    // count i s.t. (l <= i < r) && (lower <= v[i] < upper)
    int range_freq(int l, int r, T lower, T upper) {
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    // max v[i] s.t. (l <= i < r) && (v[i] < upper)
    T prev_value(int l, int r, T upper) {
        int cnt = range_freq(l, r, upper);
        return cnt == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);
    }

    // min v[i] s.t. (l <= i < r) && (lower <= v[i])
    T next_value(int l, int r, T lower) {
        int cnt = range_freq(l, r, lower);
        return cnt == r - l ? T(-1) : kth_smallest(l, r, cnt);
    }
};

template< typename T, int MAXLOG >
struct CompressedWaveletMatrix {
    WaveletMatrix< int, MAXLOG > mat;
    vector< T > ys;

    CompressedWaveletMatrix(const vector< T > &v) : ys(v) {
        sort(begin(ys), end(ys));
        ys.erase(unique(begin(ys), end(ys)), end(ys));
        vector< int > t(v.size());
        for(int i = 0; i < v.size(); i++) t[i] = get(v[i]);
        mat = WaveletMatrix< int, MAXLOG >(t);
    }

    inline int get(const T& x) {
        return lower_bound(begin(ys), end(ys), x) - begin(ys);
    }

    T access(int k) {
        return ys[mat.access(k)];
    }

    T operator[](const int &k) {
        return access(k);
    }

    int rank(const T &x, int r) {
        auto pos = get(x);
        if(pos == ys.size() || ys[pos] != x) return 0;
        return mat.rank(pos, r);
    }

    T kth_smallest(int l, int r, int k) {
        return ys[mat.kth_smallest(l, r, k)];
    }

    T kth_largest(int l, int r, int k) {
        return ys[mat.kth_largest(l, r, k)];
    }

    int range_freq(int l, int r, T upper) {
        return mat.range_freq(l, r, get(upper));
    }

    int range_freq(int l, int r, T lower, T upper) {
        return mat.range_freq(l, r, get(lower), get(upper));
    }

    T prev_value(int l, int r, T upper) {
        auto ret = mat.prev_value(l, r, get(upper));
        return ret == -1 ? T(-1) : ys[ret];
    }

    T next_value(int l, int r, T lower) {
        auto ret = mat.next_value(l, r, get(lower));
        return ret == -1 ? T(-1) : ys[ret];
    }
};

int main(void){
    int N;
    cin >> N;
    vector<pint> xy(N);
    rep(i,N) cin >> xy[i].fi >> xy[i].se;
    sort(all(xy));
    vector<lint> x(N),y(N);
    rep(i,N) x[i]=xy[i].fi,y[i]=xy[i].se;
    CompressedWaveletMatrix<lint,18> WM(y);
    lint lo=-1,hi=1.2e9;
    while(hi-lo>1){
        lint mid=(hi+lo)/2;
        bool find=false;
        rep(i,N){
            lint r=lower_bound(all(x),x[i]+mid)-x.begin();
            if(r==N) continue;
            int cnt=0;
            cnt+=WM.range_freq(r,N,y[i]+mid,LINF);
            cnt+=WM.range_freq(r,N,-LINF,y[i]-mid+1);
            if(cnt>0){
                find=true;
                break;
            }
        }
        if(find) lo=mid;
        else hi=mid;
    }
    cout << lo << endl;
}