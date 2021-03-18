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

int main() {
  int n;
  ll l;
  cin >> n >> l;
  vector<ll> time(n);
  priority_queue<pair<ll,int>> pq;
  rep(i, n){
    ll t;
    cin >> t;
    pq.push({t, i});
  }
  while (!pq.empty()){
    auto d = pq.top();
    ll minute = d.first;
    int i = d.second;
    if(i == 0){
      time[i] = time[i + 1] + (l - minute);
    }else if(i == n -1){
      time[i] = time[i - 1] + (l - minute);
    }else {
      time[i] = max(time[i - 1], time[i+1]) + (l - minute);
    }
    pq.pop();
  }
  ll ans = *max_element(ALL(time));
  cout << ans << endl;
}