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

//広義最長減少部分列
int LDS(vector<ll> &A){
  int n = A.size();
  deque<ll> d;
  rep(i, n){
    int p = lower_bound(ALL(d), A[i]) - d.begin();
    if(p == 0){
      d.push_front(A[i]);
    }else{
      d[p - 1] = A[i];
    }
  }
  return d.size();
}

int main() {
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  int ans = LDS(A);
  cout << ans << endl;
}