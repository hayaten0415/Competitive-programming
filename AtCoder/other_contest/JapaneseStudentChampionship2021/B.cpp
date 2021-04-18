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

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n), B(m);
  vector<int> cn_A(1001), cn_B(1001);
  rep(i, n){
    cin >> A[i];
    cn_A[A[i]]++;
  }
  rep(i, m){
    cin >> B[i];
    cn_B[B[i]]++;
  }
  rep(i, 1001){
    if (cn_A[i] > 0 && cn_B[i] > 0)continue;
    if (cn_A[i] > 0 || cn_B[i] > 0){
      cout << i << " ";
    }
  }
  cout << endl;
}