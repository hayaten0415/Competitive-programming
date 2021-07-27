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


void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  vector<int> ind(n);
  vector<int> ans(n);
  vector<int> cn(n + 1);
  rep(i, n)ind[i] = i;
  map<int, int> mp2;
  rep(i, n){
    cin >> A[i];
    cn[A[i]]++;
  }
  int sum = 0;
  rep(i, n+1){
    sum += min(k, cn[i]);
  }
  sort(ind.begin(), ind.end(), [&](int x, int y){
      return A[x] < A[y];
  });
  sort(A.begin(), A.end(), [&](int x, int y){
      return x < y;
  });
  map<int, int> mp;
  vector<int> cn2(k);
  int mx = sum / k;
  bool ok = true;
  int a = 0;
  rep(i, n){
    if(mp[A[i]] ==k){
      continue;
    }else{
      if(cn2[a] == mx)break;
      mp[A[i]]++;
      ans[ind[i]] = a + 1;
      cn2[a]++;
      a++;
      if(a == k)a = 0;
    }
  }
  rep(i, n){
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}