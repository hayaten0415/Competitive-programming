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
  rep(i, n){
    cin >> A[i];
  }
  ll left = 0;
  ll right = 0;
  ll b = 0;
  ll sum = 0;
  ll ans = 0;
  while (left < n){
    while (right < n && (A[right] ^ b) == sum + A[right]){
      b ^= A[right];
      sum += A[right];
      right++;
    }
    ll length = right - left;
    ans += length;
    b ^= A[left];
    sum -= A[left];
    left++;
  }
  cout << ans << endl;
}