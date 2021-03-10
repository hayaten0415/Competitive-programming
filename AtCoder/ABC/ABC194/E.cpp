#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> cnt(n + 1);
  vector<int> A(n);
  set<int> st;
  rep(i, n + 1) st.insert(i);
  rep(i, n) cin >> A[i];
  rep(i, m){
    cnt[A[i]]++;
    st.erase(A[i]);
  }
  int ans = (1 << 30);
  rep(i, n- m + 1){
    int d = *st.begin();
    chmin(ans, d);
    cnt[A[i]]--;
    if(cnt[A[i]] == 0){
      st.insert(A[i]);
    }
    if(i + m < n){
      st.erase(A[i + m]);
      cnt[A[i+m]]++;
    }
  }
  cout << ans << endl;
}