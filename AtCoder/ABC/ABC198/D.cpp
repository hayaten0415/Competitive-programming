#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  set<char> st;
  vector<int> num(10);
  vector<int> al_num(26);
  vector<char> alpha;
  int n = s1.size();
  int m = s2.size();
  int k = s3.size();
  rep(i, n){
    if(st.find(s1[i]) != st.end())continue;
    st.insert(s1[i]);
    alpha.pb(s1[i]);
  }
  rep(i, m){
    if(st.find(s2[i]) != st.end())continue;
    st.insert(s2[i]);
    alpha.pb(s2[i]);
  }
  rep(i, k){
    if(st.find(s3[i]) != st.end())continue;
    st.insert(s3[i]);
    alpha.pb(s3[i]);
  }
  if(st.size() > 10){
    cout << "UNSOLVABLE" << endl;
    return 0;
  }
  rep(i, 10) num[i] = i;
  int f = alpha.size();
  do{
    al_num.assign(26, -1);
    rep(i, f){
      int s = alpha[i] - 'a';
      al_num[s] = num[i];
    }
    ll d1 = 0, d2 = 0, d3 = 0;
    bool zero = false;
    rep(i, n){
      int s = s1[i] - 'a';
      if(i == 0 && al_num[s] == 0)zero = true;
      d1 *= 10;
      d1 += al_num[s];
    }
    rep(i, m){
      int s = s2[i] - 'a';
      if(i == 0 && al_num[s] == 0)zero = true;
      d2 *= 10;
      d2 += al_num[s];
    }
    rep(i, k){
      int s = s3[i] - 'a';
      if(i == 0 && al_num[s] == 0)zero = true;
      d3 *= 10;
      d3 += al_num[s];
    }
    if(zero)continue;
    if(d1 + d2 == d3){
      cout << d1 << endl;
      cout << d2 << endl;
      cout << d3 << endl;
      return 0;
    }
  } while (next_permutation(ALL(num)));
  cout << "UNSOLVABLE" << endl;
  return 0;
}