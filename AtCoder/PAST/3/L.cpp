#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int main() {
  int n;
  cin >> n;
  set<int> st1, st2;
  map<int, int> mp;
  vector<stack<int>> tmp(n);
  rep(i, n){
    int k;
    cin >> k;
    vector<int> A(k);
    int cn = 0;
    rep(j, k){
      cin >> A[j];
      mp[A[j]] = i;
      if(cn < 1){
        st1.insert(A[j]);
        st2.insert(A[j]);
      }
      if(cn < 2){
        st2.insert(A[j]);
      }
      cn++;
    }
    rrep(j, k){
      tmp[i].push(A[j]);
    }
  }
  int m;
  cin >> m;
  vector<int> A(m);
  rep(i, m) cin >> A[i];
  rep(i, m){
    if(A[i] == 1){
      int ans = *st1.rbegin();
      cout << ans << endl;
      st1.erase(ans);
      st2.erase(ans);
      int d = mp[ans];
      tmp[d].pop();
      if(tmp[d].size() > 0){
        int next = tmp[d].top();
        st1.insert(next);
        if(tmp[d].size() > 1){
          tmp[d].pop();
          int next2 = tmp[d].top();
          st2.insert(next2);
          tmp[d].push(next);
        }
      }
    }else{
      int ans = *st2.rbegin();
      cout << ans << endl;
      st2.erase(ans);
      int d = mp[ans];
      int c = tmp[d].top();
      if(ans == c){
        tmp[d].pop();
        st1.erase(ans);
        if(tmp[d].size() > 0){
          int next = tmp[d].top();
          st1.insert(next);
          if(tmp[d].size() > 1){
            tmp[d].pop();
            int next2 = tmp[d].top();
            st2.insert(next2);
            tmp[d].push(next);
          }
        }
      }else{
        tmp[d].pop();
        tmp[d].pop();
        if(tmp[d].size() > 0){
          int next2 = tmp[d].top();
          st2.insert(next2);
        }
        tmp[d].push(c);
      }
    }
  }
}