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

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> W(n), V(n), X(m);
  rep(i, n) cin >> W[i] >> V[i];
  rep(i, m) cin >> X[i];
  rep(i, q){
    int a, b;
    cin >> a >> b;
    a--;
    vector<int> X2;
    rep(j, m){
      if (j < a || b <= j){
        X2.push_back(X[j]);
      }
    }
    sort(ALL(X2));
    int k = X2.size();
    int ans = 0;
    vector<bool> used(n, false);
    rep(j, k){
      priority_queue<P> pq;
      rep(s, n){
        if(X2[j] >= W[s] & !used[s]){
          pq.push({V[s], s});
        }
      }
      if (!pq.empty()){
        ans += pq.top().first;
        used[pq.top().second] = true;
        pq.pop();
      }
    }
    cout << ans << endl;
  }
}