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
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int a, b, k;
  cin >> a >> b >> k;
  vector<P> AB(k);
  ll ans = 0;
  vector<int> sum_a(a + 1, 0), b_cn(b + 1, 0);
  rep(i, k){
    cin >> AB[i].first;
    sum_a[AB[i].first]++;
  }
  rep(i, k){
    cin >> AB[i].second;
    b_cn[AB[i].second]++;
  }
  sort(ALL(AB));
  rep(i, a){
    sum_a[i + 1] = sum_a[i] + sum_a[i + 1];
  }
  rep(i, k){ 
    ll num = sum_a[a] - sum_a[AB[i].first];
    //cout << num << " " << AB[i].first << " " << b_cn[AB[i].second] << endl;
    ans += (num - b_cn[AB[i].second] +1);
    //cout << "ans" << " " << ans << endl;
    b_cn[AB[i].second]--;
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}