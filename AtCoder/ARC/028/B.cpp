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
  int n, k;
  cin >> n >> k;
  vector<P> X(n);
  priority_queue<P> pq_k;
  int cn = 0;
  rep(i, n){
    int rank = i + 1;
    int young;
    cin >> young;
    X[i] = {young, rank};
    if(cn < k)pq_k.push(X[i]);
    cn++;
  }
  vector<int> ans;
  P p = pq_k.top();
  int num = p.second;
  ans.emplace_back(num);
  for (int i = k; i < n; i++){
    P p = pq_k.top();
    if(p.first > X[i].first){
      pq_k.pop();
      pq_k.push(X[i]);
    }
    ans.emplace_back(pq_k.top().second);
  }
  rep(i, n - k + 1){
    cout << ans[i] << endl;
  }
}