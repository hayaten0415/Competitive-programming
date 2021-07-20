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
  int k, n, m;
  cin >> k >> n >> m;
  vector<int> A(n), B(m);
  rep(i, n) cin >> A[i];
  rep(i, m) cin >> B[i];
  int a = 0, b = 0;
  vector<int> ans;
  bool ok = true;
  priority_queue<P, vector<P>, greater<P>> A_A;
  priority_queue<P, vector<P>, greater<P>> B_B;
  rep(i, n){
    if(A[i] != 0){
      A_A.push({i, A[i]});
    }
  }
  rep(i, m){
    if(B[i] != 0){
      B_B.push({i, B[i]});
    }
  }
  rep(i, n + m){
    if(a < n && b < m){
      if (A[a] != 0 && B[b] == 0){
        if (k >= A[a]){
          ans.pb(A[a]);
          if(A_A.top().first == a){
            A_A.pop();
          }
          a++;
          continue;
        }else{
          ans.pb(B[b]);
          b++;
          k++;
          continue;
        }
      }
      if (A[a] == 0 && B[b] != 0){
        if (k >= B[b]){
          ans.pb(B[b]);
          if(B_B.top().first == b){
            B_B.pop();
          }
          b++;
          continue;
        }else{
          ans.pb(A[a]);
          k++;
          a++;
          continue;
        }
      }
      if (A[a] != 0 && B[b] != 0){
        if (k >= B[b]){
          ans.pb(B[b]);
          if(B_B.top().first == b){
            B_B.pop();
          }
          b++;
          continue;
        }
        if(k >= A[a]){
          ans.pb(A[a]);
          if(A_A.top().first == a){
            A_A.pop();
          }
          a++;
          continue;
        }
        if(A[a] > k && B[b] > k){
          ok = false;
          break;
        }
      }
      if (A[a] == 0 && B[b] == 0){
        if(!A_A.empty() && !B_B.empty()){
          int an = A_A.top().second;
          int bn = B_B.top().second;
          if(an <= bn){
            ans.pb(A[a]);
            a++;
            k++;
          }else{
            ans.pb(B[b]);
            b++;
            k++;
          }
          continue;
        }else if(!A_A.empty()){
          ans.pb(A[a]);
          a++;
          k++;
        }else if(!B_B.empty()){
          ans.pb(B[b]);
          b++;
          k++;
        }else{
          if(a < n){
            ans.pb(A[a]);
            a++;
            k++;
            continue;
          }
          if(b < m){
            ans.pb(B[b]);
            b++;
            k++;
            continue;
          }
        }  
      }
    }else if(b == m && a< n){
      if (A[a] != 0){
        if(A[a] > k){
          ok = false;
          break;
        }else{
          ans.pb(A[a]);
          if(A_A.top().first == a){
            A_A.pop();
          }
          a++;
        }
      }
      else
      {
        ans.pb(A[a]);
        k++;
        a++;
      }
    }else if(a == n && b < m){
      if(B[b] != 0){
        if(B[b] > k){
          ok = false;
          break;
        }else{
          ans.pb(B[b]);
          if(B_B.top().first == b){
            B_B.pop();
          }
          b++;
        }
      }else{
        ans.pb(B[b]);
        k++;
        b++;
      }
    }
  }
  //cout << ans.size() << endl;
  if(!ok){
    cout << -1 << endl;
  }else{
    rep(i, n+m){
      cout << ans[i] << (i == n + m - 1 ? "\n" : " ");
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