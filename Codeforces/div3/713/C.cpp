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
  int a, b;
  cin >> a >> b;
  string s;
  cin >> s;
  int n = s.size();
  bool ok = true;
  vector<int> p;
  rep(i, n){
    if(s[i] != '?' && s[n-i -1] != '?'){
      if(s[i] != s[n-i -1])ok =false;
    }
    if(s[i] == '?' && s[n-i -1] != '?'){
      s[i] = s[n-i -1];
    }
    if(s[i] != '?' && s[n-i -1] == '?'){
      s[n-i -1] = s[i];
    }
    if(s[i] == '?' && s[n-i -1] == '?' && i != n- i -1){
      p.push_back(i);
    }
  }
  vector<int> cnt(2, 0);
  rep(i, n){
    if (s[i] != '?'){
      cnt[s[i] - '0']++;
    }
  }
  if (cnt[0] > a || cnt[1] > b){
    ok = false;
  }
  if (!ok){
    cout << -1 << endl;
    return;
  }else{
    int c = p.size();
    int c1 = (a - cnt[0]) / 2;
    int c2 = (b - cnt[1]) / 2;
    rep(i, c1){
      s[p[i]] = '0';
      s[n - 1 - p[i]] = '0';
    }
    for (int i = c1; i < c1 + c2; i++){
      s[p[i]] = '1';
      s[n - 1 - p[i]] = '1';
    }
    cnt[0] += c1 * 2;
    cnt[1] += c2 * 2;
    if (n % 2 == 1 && s[n / 2] == '?'){
      if (cnt[0] != a){
        s[n / 2] = '0';
      } else {
        s[n / 2] = '1';
      }
    }
    vector<int> cnt2(2, 0);
    rep(j, n){
      if(s[j] == '0')cnt2[0]++;
      if(s[j] == '1')cnt2[1]++;
    }
    if (cnt2[0] == a && cnt2[1] == b){
      cout << s << endl;
    } else {
      cout << -1 << endl;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}