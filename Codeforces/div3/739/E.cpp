#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max() / 2;


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> al;
  vector<bool> used(26, 0);
  rrep(i, n){
    if(!used[s[i] - 'a']){
      used[s[i] - 'a'] = true;
      al.eb(s[i] - 'a');
    }
  }
  vector<int> cn(26);
  rep(i, n){
    cn[s[i] - 'a']++;
  }
  int f = al.size();
  vector<int> cn2(26);
  bool ok = true;
  rep(i, f){
    if(cn[al[i]] % (f- i) != 0){
      ok = false;
    }else{
      cn2[al[i]] = cn[al[i]] / (f - i);
    }
  }
  if(!ok){
    cout << -1 << endl;
  }else{
    reverse(ALL(al));
    int sum = 0;
    rep(i, 26){
      sum += cn2[i];
    }
    string res = s.substr(0, sum);
    string t;
    vector<bool> ng(26);
    rep(i, f){
      rep(j, sum){
        if(ng[res[j] - 'a'])continue;
        t += res[j];
      }
      ng[al[i]] = true;
    }
    if(t == s){
      cout << res << " ";
      for(int d : al){
        cout << char(d + 'a');
      }
      cout << endl;
    }else{
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