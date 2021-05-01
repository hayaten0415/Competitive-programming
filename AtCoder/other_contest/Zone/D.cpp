#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  string s;
  cin >> s;
  int n = s.size();
  deque<char> de;
  int flip = 0;
  rep(i, n){
    if(s[i] == 'R'){
      flip ^= 1;
      continue;
    }
    if(!flip) de.push_back(s[i]);
    else de.push_front(s[i]);
  }
  if(flip)reverse(ALL(de));
  string ans = "";
  for(auto c : de)ans += c;

  stack<char> st;
  int k = ans.size();
  rep(i, k){
    if(st.empty()){
      st.push(ans[i]);
      continue;
    }else{
      st.push(ans[i]);
      while (true){
        if(st.size() < 2)break;
        char d = st.top();
        st.pop();
        char e = st.top();
        if(d == e){
          st.pop();
          continue;
        }else{
          st.push(d);
          break;
        }
      }
    }
  }
  string res = "";
  while(!st.empty()){
    char d = st.top();
    res += d;
    st.pop();
  }
  reverse(ALL(res));
  cout << res << endl;
}