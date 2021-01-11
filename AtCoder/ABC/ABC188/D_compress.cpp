#include <bits/stdc++.h>
#include<atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//0-indexedに変換想定
template <typename T>
map<T, int> compress(vector<T> &A, vector<T> &B) {
  int n = A.size();
  map<T, int> mp;
  int cn = 0;
  rep(i, n){
    mp[A[i]] = 0;
    mp[B[i]] = 0;
  }
  for (auto &p : mp){
    p.second = cn;
    cn++;
  }
  return mp;
}

int main(){
  int n;
  ll c;
  cin >> n >> c;
  vector<ll> A(n), B(n), C(n);
  rep(i, n){
    cin >> A[i] >> B[i] >> C[i];
    //デクリメントを忘れてはいけない
    A[i]--;
  }
  map<ll, int> mp = compress(A, B);
  vector<ll> imos(mp.size());
  vector<ll> change(mp.size());
  rep(i, n){
    change[mp[A[i]]] = A[i];
    change[mp[B[i]]] = B[i];
    imos[mp[A[i]]] += C[i];
    imos[mp[B[i]]] -= C[i];
  }
  rep(i, mp.size()-1){
    imos[i+1] += imos[i];
  }
  ll ans = 0;
  for(int i = 0; i < mp.size()-1; i++){
    ans += min(imos[i], c) * (change[i + 1] - change[i]);
  }
  cout << ans << endl;
}
