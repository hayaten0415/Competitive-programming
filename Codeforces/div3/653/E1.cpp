#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

void solve() {
  int n, k;
  cin >> n >> k;
  priority_queue<ll, vector<ll>, greater<ll>> Alice_Bob, Alice, Bob;
  rep(i, n){
    ll t;
    int a, b;
    cin >> t >> a >> b;
    if(a == 1 && b == 1){
      Alice_Bob.push(t);
    }else if(a == 1){
      Alice.push(t);
    }else if(b == 1){
      Bob.push(t);
    }
  }
  ll ans = 0;
  if(Alice_Bob.size() + min(Alice.size() , Bob.size()) < k){
    cout << -1 << endl;
  }else{
    rep(i, k){
      if(!Alice_Bob.empty()){
        ll A = Alice_Bob.top();
        if(!Alice.empty() & !Bob.empty()){
          ll B = Alice.top();
          ll C = Bob.top();
          if(A < B + C){
            ans += A;
            Alice_Bob.pop();
          }else{
            ans += (B + C);
            Alice.pop();
            Bob.pop();
          }
        }else{
          ans += A;
          Alice_Bob.pop();
        }
      }else{
        ll B = Alice.top();
        ll C = Bob.top();
        ans += (B + C);
        Alice.pop();
        Bob.pop();
      }
    }
    cout << ans << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}