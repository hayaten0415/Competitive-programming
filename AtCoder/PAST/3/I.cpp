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
  ll n, q;
  cin >> n >> q;
  vector<ll> row(n), column(n);
  vector<ll> ans;
  rep(i, n){
    row[i] = i;
    column[i] = i;
  }
  int tenchi = 0;
  rep(i, q){
    int query;
    cin >> query;
    if(query == 1){
      int a, b;
      cin >> a >> b;
      a--, b--;
      if(a == b)continue;
      if(tenchi % 2 == 0){
        swap(row[a], row[b]);
      }else{
        swap(column[a], column[b]);
      }
    }else if(query == 2){
      int a, b;
      cin >> a >> b;
      a--, b--;
      if(a == b)continue;
      if(tenchi % 2 == 0){
        swap(column[a], column[b]);
      }else{
        swap(row[a], row[b]);
      }
    }else if(query == 3){
      tenchi++;
    }else{
      int a, b;
      cin >> a >> b;
      a--, b--;
      if(tenchi % 2 == 0){
        ans.emplace_back(n * row[a] + column[b]);
      }else{
        ans.emplace_back(n * row[b] + column[a]);
      }
    }
  }
  rep(i, ans.size()){
    cout << ans[i] << endl;
  }
}