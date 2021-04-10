#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
const ll INF = (1LL << 50);

int main() {
  int n;
  cin >> n;
  vector<int> C(n);
  vector<ll> X(n);
  rep(i, n) cin >> X[i] >> C[i];
  vector<int> C2 = C;
  sort(ALL(C2));
  C2.erase(unique(ALL(C2)), C2.end());
  int m = C2.size();
  rep(i, n){
    C[i] = lower_bound(ALL(C2), C[i]) - C2.begin() + 1;
  }
  vector<ll> L(m + 2, INF), R(m + 2, -INF);
  rep(i, n){
    chmin(L[C[i]], X[i]);
    chmax(R[C[i]], X[i]);
  }
  L[0] = 0;
  R[0] = 0;
  L[m + 1] = 0;
  R[m + 1] = 0;
  vector<long long> dpL(m + 2), dpR(m + 2);
  dpL[0] = 0;
  dpR[0] = 0;
  rep(i, m+1){
    dpL[i + 1] = min(dpL[i] + abs(R[i + 1] - L[i]), dpR[i] + abs(R[i + 1] - R[i])) + R[i + 1] - L[i + 1];
    dpR[i + 1] = min(dpL[i] + abs(L[i + 1] - L[i]), dpR[i] + abs(L[i + 1] - R[i])) + R[i + 1] - L[i + 1];
  }
  cout << min(dpL[m + 1], dpR[m + 1]) << endl;
}