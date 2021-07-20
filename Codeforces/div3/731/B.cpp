#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
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


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  vector<int> ind(n, -1);
  rep(i, n){
    int d = s[i] - 'a';
    if(d >= n){
      ok = false;
      break;
    }
    ind[d] = i;
  }
  rep(i, n)if(ind[i] == -1)ok = false;
  if(!ok){
    cout << "NO" << endl;
    return;
  }
  deque<char> deq;
  deq.pb('a');
  int left = ind[0], right = ind[0];
  rep(i, n-1){
    char tmp = char('a' + (i + 1));
    if(ind[i+1] < left){
      left = ind[i + 1];
      deq.push_front(tmp);
    }
    if(ind[i+1] > right){
      right = ind[i + 1];
      deq.push_back(tmp);
    }
  }
  string tmp = "";
  while(!deq.empty()){
    char d = deq.front();
    tmp += d;
    deq.pop_front();
  }
  if(tmp != s)ok = false;
  if(ok){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}