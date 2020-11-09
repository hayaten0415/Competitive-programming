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
  int N;
  ll K;
  cin >> N >> K;
  vector<ll> A(N), F(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> F[i];
  sort(ALL(F));
  sort(ALL(A),greater<ll>());
  ll left = -1;
  ll right = (1LL << 60);
  while(right - left > 1){
    ll mid = (left + right) / 2;
    auto ok = [&](ll x) {
      ll tmp = 0;
      rep(i,N){
        if (A[i] -(x / F[i]) <= 0)continue;
        tmp += A[i] - (x / F[i]);
      }
      if(tmp > K)return false;
      else return true;
    };
    if(ok(mid))right = mid;
    else left = mid;
  }
  cout << right << endl;
}