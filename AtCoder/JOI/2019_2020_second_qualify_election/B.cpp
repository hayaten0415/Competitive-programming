#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using PLL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<PLL> A(n);
  ll max_a = 0;
  ll max_a_t = 0;
  rep(i, n){
    ll a, t;
    cin >> a >> t;
    A[i] = {t, a};
    chmax(max_a, a);
  }
  ll time = max_a * 2;
  sort(ALL(A));
  rep(i, n){
    if(2 * max_a - A[i].second < A[i].first){
      chmax(time, A[i].second + A[i].first);
    }
  }
  cout << time << endl;
}