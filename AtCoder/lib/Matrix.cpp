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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;


template<typename T> class Matrix{
private:
    typedef long long int ll;
 
    T zero=0,e=1;
    vector<vector<T>> vec_matrix;
    void init(int n,int m);
    function<bool(T,T)> same=[](T a,T b){return a==b;};
    //function<bool(T,T)> same=[](T a,T b){return (a-b)<=1e-9;};
 
    Matrix gauss_and_inverse(int mode)const;
public:
    Matrix(int n);
    Matrix(int n,int m);
    Matrix(vector<vector<T>>& ma);
 
    int sizeX() const;
    int sizeY() const;
    bool valid() const;
 
    T& element(int a,int b);
    const vector<vector<T>>& get_vec()const;
    void set_same_function(function<bool(T,T)> _same){same=_same;}
 
    void E();
    void E(int n);
    Matrix& operator += (const Matrix& mat_a);
    Matrix& operator -= (const Matrix& mat_a);
    Matrix& operator *= (const Matrix& mat_a);
    friend Matrix operator +(const Matrix& mat_a,const Matrix& mat_b){return (Matrix)mat_a+=mat_b;}
    friend Matrix operator -(const Matrix& mat_a,const Matrix& mat_b){return (Matrix)mat_a-=mat_b;}
    friend Matrix operator *(const Matrix& mat_a,const Matrix& mat_b){return (Matrix)mat_a*=mat_b;}
    
    Matrix operator+() const{return *this;}
    Matrix operator-() const{return Matrix()-*this;}
 
    Matrix& operator %= (const T mod);
 
    Matrix pow_mod(ll m,ll mod=1e9+7)const;
    Matrix pow(ll m)const;
 
    T tr()const;
    Matrix gauss()const;
    T det()const;
    Matrix inverse()const;
    Matrix submatrix(int a,int b,int c,int d)const;//[a,c)*[b,d)
};
 
template<typename T> void Matrix<T>::init(int n,int m){
    vec_matrix.assign(n,vector<T>(m,zero));
}
template<typename T> bool Matrix<T>::valid() const{
    int n=sizeX(),m=sizeY();
    for(int i=0;i<n;i++){
        if((int)vec_matrix[i].size()!=m)return false;
    }
    return true;
}
 
template<typename T> Matrix<T>::Matrix(int n){
    init(n,n);
}
template<typename T> Matrix<T>::Matrix(int n,int m){
    init(n,m);
}
template<typename T> Matrix<T>::Matrix(vector<vector<T>>& ma):vec_matrix(ma){
    assert(valid());
};
 
template<typename T> int Matrix<T>::sizeX() const{
    return vec_matrix.size();
}
template<typename T> int Matrix<T>::sizeY() const{
    if(vec_matrix.empty())return 0;
    return vec_matrix[0].size();
}
 
template<typename T> void Matrix<T>::E(){
    assert(sizeX()==sizeY());
    int n=sizeX();
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            vec_matrix[i][j]=(i==j)?e:zero;
        }
    }
}
template<typename T> void Matrix<T>::E(int n){
    init(n,n);
    E();
}
 
template<typename T> Matrix<T>& Matrix<T>::operator += (const Matrix<T>& mat){
    const vector<vector<T>>& vec_mat=mat.get_vec;
    assert(sizeX()==mat.sizeX() && sizeY()==mat.sizeY());
    int i,j;
    int n=sizeX(),m=sizeY();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vec_matrix[i][j]+=vec_mat[i][j];
        }
    }
    return *this;
}
 
template<typename T> Matrix<T>& Matrix<T>::operator -= (const Matrix<T>& mat){
    const vector<vector<T>>& vec_mat=mat.get_vec;
    assert(sizeX()==mat.sizeX() && sizeY()==mat.sizeY());
    int i,j;
    int n=sizeX(),m=sizeY();
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            vec_matrix[i][j]-=vec_mat[i][j];
        }
    }
    return *this;
}
 
template<typename T> Matrix<T>& Matrix<T>::operator *= (const Matrix<T>& mat){
    const vector<vector<T>>& vec_mat=mat.get_vec();
    assert(mat.sizeX()==sizeY());
    int i,j,k;
    int n=sizeX(),m=mat.sizeY(),p=sizeY();
    vector<vector<T>> vec_mats(n,vector<T>(m,zero));
    for(i=0;i<n;i++){
        for(k=0;k<p;k++){
            for(j=0;j<m;j++){
                vec_mats[i][j]+=vec_matrix[i][k]*vec_mat[k][j];
            }
        }
    }
    vec_matrix=vec_mats;
    return *this;
}
 
template<typename T> Matrix<T>& Matrix<T>::operator %= (const T mod){
    for(auto& vm:vec_matrix){
        for(auto& num:vm){
            if(num>=mod)num%=mod;
        }
    }
    return *this;
}
 
template<typename T> istream& operator >> (istream& is,Matrix<T>& a){
    assert(a.valid());
    int n=a.sizeX(),m=a.sizeY();
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            is>>a.element(i,j);
        }
    }
    return is;
}
 
template<typename T> ostream& operator << (ostream& os,Matrix<T>& a){
    assert(a.valid());
    int n=a.sizeX(),m=a.sizeY();
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(j)cout<<" ";
            os<<a.element(i,j);
        }
        os<<endl;
    }
    return os;
}
 
template<typename T> Matrix<T> Matrix<T>::pow_mod(ll m,ll mod)const{
    assert(sizeX()==sizeY());
    ll p_b=1;
    Matrix<T> ms(sizeX());
    ms.E();
    for(;p_b<=m;p_b<<=1);
    for(p_b>>=1;p_b>0;p_b>>=1){
        ms*=ms;
        ms%=mod;
        if(m&p_b)ms*=(*this);
        ms%=mod;
    }
    return ms;
}
 
template<typename T> Matrix<T> Matrix<T>::pow(ll m)const{
    assert(sizeX()==sizeY());
    Matrix<T> ms(sizeX()),ma=*this;
    ms.E();
    for(int i=0;(1LL<<i)<=m;i++){
        if(m&1LL<<i)ms*=ma;
        ma*=ma;
    }
    return ms;
}
 
template<typename T> T& Matrix<T>::element(int a,int b){
    assert(0<=a && a<sizeX() && 0<=b && b<sizeY());
    return vec_matrix[a][b];
}
template<typename T> const vector<vector<T>>& Matrix<T>::get_vec() const{
    return vec_matrix;
}
 
template<typename T> T Matrix<T>::tr()const{
    assert(sizeX()==sizeY());
    int n=sizeX();
    T a=e;
    for(int i=0;i<n;i++){
        a*=vec_matrix[i][i];
    }
    return a;
}
 
template<typename T> Matrix<T> Matrix<T>::gauss_and_inverse(int mode)const{
    //mode: 0: gauss triangle, 1: inverse
    int n=sizeX(),m=sizeY();
    int i,j,k,l;
    vector<vector<T>> v=vec_matrix,inv(n,vector<T>(m));
    if(mode==1){
        assert(n==m);
        for(i=0;i<min(n,m);i++)inv[i][i]=e;
    }
    for(i=0,j=0;i<m;i++){
        for(k=j;k<n;k++){
            if(!same(v[k][i],zero))break;
        }
        if(k==n)continue;
        if(j<k){
            //swap j_th and k_th row
            for(l=0;l<m;l++){
                swap(v[j][l],v[k][l]);
                if(mode==1)swap(inv[j][l],inv[k][l]);
            }
        }
        for(k=j+1;k<n;k++){
            T a=v[k][i]/v[j][i];
            if(a==zero)continue;
            for(l=i+1;l<m;l++)v[k][l]-=v[j][l]*a;
            v[k][i]=zero;
            if(mode==1){
                for(l=0;l<m;l++)inv[k][l]-=inv[j][l]*a;
            }
        }
        j++;
    }
    if(mode==0)return Matrix(v);
 
    //fix inverse
    for(i=n-1;i>=0;i--){
        if(v[i][i]==zero)assert(false);
        for(j=0;j<i;j++){
            T a=v[j][i]/v[i][i];
            if(a==zero)continue;
            for(k=0;k<m;k++){
                inv[j][k]-=inv[i][k]*a;
            }
        }
        for(k=0;k<m;k++){
            inv[i][k]/=v[i][i];
        }
    }
    return Matrix(inv);
}
 
template<typename T> Matrix<T> Matrix<T>::gauss()const{
    return gauss_and_inverse(0);
}
template<typename T> T Matrix<T>::det()const{
    assert(sizeX()==sizeY());
    Matrix a=gauss();
    T s=e;
    for(int i=0;i<sizeX();i++){
        s*=a.element(i,i);
    }
    return s;
}
template<typename T> Matrix<T> Matrix<T>::inverse()const{
    return gauss_and_inverse(1);
}
 
template<typename T> Matrix<T> Matrix<T>::submatrix(int a,int b,int c,int d)const{
    //[a,c)*[b,d)
    assert(0<=a && a<c && c<=sizeX());
    assert(0<=b && b<d && d<=sizeY());
    Matrix<T> s(c-a,d-b);
    int i,j;
    for(i=0;i<c-a;i++){
        for(j=0;j<d-b;j++){
            s.element(i,j)=vec_matrix[a+i][b+j];
        }
    }
    return s;
}
 
using mint = modint1000000007;

struct UnionFind {
  vector<int> par; //par[i]:iの親の番号

  //最初は全てが根であるとする。-1のときに根である。
  UnionFind(int N) : par(N, -1){}

  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
  int root(int x) {
    if(par[x] < 0) return x;
    else return par[x] = root(par[x]);
  }
  // データxが根かどうか
  bool cond_root(int x){
    if(par[x] < 0) return true;
    else return false;
  }
  //xとyが同じ集合に属するか
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  bool merge(int x, int y) {
    x = root(x); y = root(y);
    if(x == y) return false;
    if(par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  int size(int x) {
    return -par[root(x)];
  }
  void reset(int n){
    par.assign(n,-1);
  }
};



int main() {

}