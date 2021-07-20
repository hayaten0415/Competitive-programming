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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
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
const ll INF = (1LL <<60);

int main() {
  int n;
  int k;
  cin >> n >> k;
  if(k > (int)(1e7 + 1e5)){
    cout << "No" << endl;
    return 0;
  }
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  map<int, int> mp;
  mp[0] = 1;
  rep(i, n){
    map<int, int> tmp;
    for(auto p : mp){
      int d1 = A[i];
      int d2 = floor(A[i] * 1.01);
      tmp[p.first + d1] = 1;
      tmp[p.first + d2] = 1;
    }
    swap(tmp, mp);
  }
  if(mp[k] == 1){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}