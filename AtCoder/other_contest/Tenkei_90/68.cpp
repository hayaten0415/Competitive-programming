#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

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
};


int main() {
  int n, q;
  cin >> n >> q;
  vector<int> T(q), X(q), Y(q), V(q);
	rep(i, q) {
		cin >> T[i] >> X[i] >> Y[i] >> V[i];
		--X[i], --Y[i];
	}
	vector<int> sum(n - 1, 0);
	rep(i, q){
		if (T[i] == 0) {
			sum[X[i]] = V[i];
		}
	}
  vector<ll> p(n);
  rep(i, n - 1) p[i + 1] = sum[i] - p[i];
  UnionFind uf(n);
  rep(i,q){
    if(T[i] == 0){
      uf.merge(X[i], Y[i]);
    }else{
      if(!uf.issame(X[i], Y[i])){
        cout << "Ambiguous" << endl;
      }else{
        if((X[i] + Y[i]) % 2 == 0){
          cout << -p[X[i]] + p[Y[i]] + V[i] << endl;
        }else{
          cout << p[X[i]] + p[Y[i]] - V[i] << endl;
        }
      }
    }
  }
}