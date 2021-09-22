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
int main(){

    ll N,K;
    cin >> N >> K;

    vector<PL> jewels;
    vector<ll> anss(N,0);
    vector<vector<ll>> jewel(K);
    multiset<ll> P,Q;
    multiset<PL> R,S,T;

    rep(i,N){
        ll c,v;
        cin >> c >> v;
        c--;
        jewel[c].emplace_back(v*2);
    }

    rep(i,K){
        if(jewel[i].empty())continue;
        sort(ALL(jewel[i]), greater{});
        ll sum = jewel[i][0] + jewel[i][1];
        jewel[i][0] = jewel[i][1] = sum/2;
        S.insert({sum,i});
        for(auto v:jewel[i]){
            jewels.emplace_back(v,i);
        }
        if(jewel[i].size()>=3){
            T.insert({jewel[i][0] + jewel[i][1] + jewel[i][2], i});
        }
    }

    sort(ALL(jewels), greater{});
    vector<ll> cnt(K, 0);
    ll sum = 0;
    rep(i,N){
        auto[v,c] = jewels[i];
        ll ans = -2;
        cnt[c]++;
        if(cnt[c]>=2){
            sum += v;
            anss[i] = sum;
            if(cnt[c]==2){
                R.insert({jewel[c][0] + jewel[c][1],c});
                S.erase({jewel[c][0] + jewel[c][1],c});
                if(jewel[c].size()>=3){
                    T.erase({jewel[c][0] + jewel[c][1] + jewel[c][2], c});
                }
                rep(j,2,jewel[c].size()){
                    Q.insert(jewel[c][j]);
                }
            }else{
                R.erase({jewel[c][0] + jewel[c][1],c});
                Q.erase(v);
                P.insert(v);
            }
            continue;
        }
        if(Q.size()){
            chmax(ans,sum + *Q.rbegin());
        }
        if(P.size() && S.size()){
            chmax(ans,sum - *P.begin() + S.rbegin()->first);
        }
        if(R.size() && T.size()){
            chmax(ans,sum - R.begin()->first + T.rbegin()->first);
        }
        anss[i] = ans;
        sum += v;

    }
    rep(i,N){
        cout << anss[i]/2 << endl;
    }



    //cout << ans << endl;

  return 0;
}