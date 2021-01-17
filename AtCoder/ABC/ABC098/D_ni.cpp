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
  vector<ll> A(n);
  vector<ll> sum(n + 1), xor_sum(n + 1);
  rep(i, n){
    cin >> A[i];
  }
  rep(i, n){
    sum[i + 1] = sum[i] + A[i];
    xor_sum[i + 1] = (xor_sum[i] ^ A[i]);
  }
  ll ans = 0;
  rep(i, n){
    int left = i;
    int right = n + 1;
    while (right - left > 1){
      int mid = (right + left) / 2;
      if((sum[mid] - sum[i]) == (xor_sum[mid] ^ xor_sum[i])){
        left = mid;
      }else{
        right = mid;
      }
    }
    ans += left - i;
  }
  cout << ans << endl;
}