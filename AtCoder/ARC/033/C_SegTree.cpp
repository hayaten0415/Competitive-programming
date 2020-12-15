#include <bits/stdc++.h>
#include <atcoder/all>
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

int op(int a, int b) { return (a + b); }
int e() { return int(0); }

int main() {
  vector<int> A(200000);
  segtree<int, op, e> seg(A);
  int Q;
  cin >> Q;
  for (int i = 0; i < Q; ++i) {
    int T, X;
    cin >> T >> X;
    if (T == 1) seg.set(X-1, 1); // insert X
    else {
      int l = 0, r = 200000;
      while(r - l > 1){
        int mid = (l + r) / 2;
        if(seg.prod(0, mid) < X){
          l = mid;
        }else{
          r = mid;
        }
      }
      cout << l + 1 << endl;
      seg.set(l, 0); // delete val
    }
  }
}