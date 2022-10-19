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
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
#define sz(x) ((ll)(x).size())
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline void Yes(bool b = true) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YES(bool b = true) { cout << (b ? "YES" : "NO") << '\n'; }
inline void OKNG(bool b = true) { cout << (b ? "OK" : "NG") << '\n'; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;


template<typename T>
struct RangeSet{
    set<pair<T,T>> st;
    T TINF;

    RangeSet(){
        TINF=numeric_limits<T>::max()/2;
        st.emplace(TINF,TINF);
        st.emplace(-TINF,-TINF);
    }
    // [l,r] covered?
    bool covered(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        return ite->first<=l and r<=ite->second;
    }
    bool covered(T x){
        return covered(x,x);
    }
    // [l, r]がカバーされているなら，その区間を返す. されていないなら[-TINF,-TINF]を返す
    pair<T,T> covered_by(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        if(ite->first<=l and r<=ite->second) return *ite;
        return make_pair(-TINF,-TINF);
    }
    pair<T,T> covered_by(T x){
        return covered_by(x,x);
    }
    // insert[l,r], 増加量を返す
    T insert(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        if(ite->first<=l and r<=ite->second) return T(0);
        T sum_erased=T(0);
        if(ite->first<=l and l<=ite->second+1){
            l=ite->first;
            sum_erased+=ite->second-ite->first+1;
            ite=st.erase(ite);
        }else ite=next(ite);
        while(r>ite->second){
            sum_erased+=ite->second-ite->first+1;
            ite=st.erase(ite);
        }
        if(ite->first-1<=r and r<=ite->second){
            sum_erased+=ite->second-ite->first+1;
            r=ite->second;
            st.erase(ite);
        }
        st.emplace(l,r);
        return r-l+1-sum_erased;
    }
    T insert(T x){
        return insert(x,x);
    }
    // erase [l,r], 減少量を返す
    T erase(T l,T r){
        assert(l<=r);
        auto ite=prev(st.lower_bound({l+1,l+1}));
        if(ite->first<=l and r<=ite->second){
            // 完全に1つの区間に包含されている
            if(ite->first<l)  st.emplace(ite->first,l-1);
            if(r<ite->second) st.emplace(r+1,ite->second);
            st.erase(ite);
            return r-l+1;
        }

        T ret=T(0);
        if(ite->first<=l and l<=ite->second){
            ret+=ite->second-l+1;// 消えた
            if(ite->first<l) st.emplace(ite->first,l-1);
            ite=st.erase(ite);// 次へ
        }else ite=next(ite);
        while(ite->second<=r){
            ret+=ite->second-ite->first+1;
            ite=st.erase(ite);
        }
        // 右端が区間の間にあるか
        if(ite->first<=r and r<=ite->second){
            ret+=r-ite->first+1;
            if(r<ite->second) st.emplace(r+1,ite->second);
            st.erase(ite);
        }
        return ret;
    }
    T erase(T x){
        return erase(x,x);
    }
    // number of range
    int size(){
        return (int)st.size()-2;
    }
    // mex [x,~)
    T mex(T x=0){
        auto ite=prev(st.lower_bound({x+1,x+1}));
        if(ite->first<=x and x<=ite->second) return ite->second+1;
        else return x;
    }
    void output(){
        cout<<"RangeSet : ";
        for(auto &p:st){
            if(p.first==-TINF or p.second==TINF) continue;
            cout<<"["<<p.first<<", "<<p.second<<"] ";
        }
        cout<<"\n";
    }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<RangeSet<int>> s(m);
  rep(i, n){
    int a;
    cin >> a;
    if(a + i + 1 > n)continue;
    if(a + (i + 1) * m < 0)continue;
    if(0<= a + (i + 1) && a + (i + 1) <= n){
      for(int c = 0; c < m; c++){
        if(a + (i + 1) * (c + 1) > n)break;
        s[c].insert(a + (i + 1) * (c + 1), a + (i + 1) * (c + 1));
      }
    }else{
      int st = (abs(a) + i) / (i + 1);
      for(int c = st; c <= m; c++){
        if(a + (i + 1) * c > n)break;
        s[c-1].insert(a + (i + 1) * c, a + (i + 1) * c);
      }
    }
  }
  rep(i, m){
    cout << s[i].mex() << endl;
  }
}