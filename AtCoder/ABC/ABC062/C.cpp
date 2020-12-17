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
ll H, W, all_square;
ll ans = 10000000000000000;

void solve() {
  for (ll i = 1; i < H; i++){
    ll num = i * W;
    if((H -i) % 2 == 0 || W % 2 == 0){
      chmin(ans, abs(((all_square - num) / 2) - num));
    }else{
      vector<ll> A(3);
      A[0] = num;
      if(i == H-1){
        A[1] = W / 2;
        A[2] = A[1] + 1;
        sort(ALL(A));
        chmin(ans, A[2] - A[0]);
      }else{
        A[1] = ((H - i) / 2) * W;
        A[2] = A[1] + W;
        sort(ALL(A));
        chmin(ans, A[2] - A[0]);
        A[0] = num;
        A[1] = (W / 2) * (H - i);
        A[2] = A[1] + (H - i);
        sort(ALL(A));
        chmin(ans, A[2] - A[0]);
      }
    }
  }
}

int main() {
  cin >> H >> W;
  all_square = H * W;
  solve();
  swap(H, W);
  solve();
  cout << ans << endl;
}