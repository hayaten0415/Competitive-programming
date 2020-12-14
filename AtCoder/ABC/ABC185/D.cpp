#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  vector<int> A(m);
  rep(i, m) cin >> A[i];
  if(n == m){
    cout << 0 << endl;
    return 0;
  }
  if(m == 0){
    cout << 1 << endl;
    return 0;
  }
  sort(ALL(A));
  vector<int> ans;
  if(A[0] != 1){
    ans.emplace_back(A[0] - 1);
  }
  rep(i, m-1){
    if(A[i+1] - A[i] > 1){
      ans.emplace_back(A[i + 1] - A[i] - 1);
    }
  }
  if(A[m-1] != n){
    ans.emplace_back(n - A[m-1]);
  }
  sort(ALL(ans));
  int k = ans[0];
  int res = 0;
  rep(i, ans.size()){
    res += (ans[i] + k - 1) / k;
  }
  cout << res << endl;
}