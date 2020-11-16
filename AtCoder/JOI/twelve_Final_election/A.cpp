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
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> sum(1, 0);
  rep(i, n) cin >> A[i];
  int tmp = A[0];
  int cn = 0;
  rep(i, n){
    if(A[i] == tmp){
      cn++;
      tmp = tmp ^ 1;
    }
    else{
      sum.emplace_back(cn);
      cn = 1;
    }
  }
  sum.emplace_back(cn);
  int k = sum.size();
  rep(i, k-1){
    sum[i + 1] = sum[i] + sum[i + 1];
  }
  if(k <= 4){
    cout << n << endl;
    return 0;
  }
  int ans = 0;
  for (int s = 3; s < k; s++){
    chmax(ans, sum[s] - sum[s - 3]);
  }
  cout << ans << endl;
}