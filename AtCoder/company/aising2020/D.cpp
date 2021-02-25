#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};


int two_a[220000];
int two_b[220000];

int main() {
  int n;
  string s;
  cin >> n >>s;
  int cn = 0;
  rep(i, n){
    if(s[i] == '1')cn++;
  }
  int a = cn - 1;
  int b = cn + 1;
  int num = 1;
  two_a[0] = num;
  if(a > 0){
    two_a[0] %= a;
  }
  two_b[0] = num;
  two_b[0] %= b;
  rep(i, 219999){
    two_b[i + 1] = two_b[i] * 2;
    two_b[i + 1] %= b;
    if(a > 0){
      two_a[i + 1] = two_a[i] * 2;
      two_a[i + 1] %= a;
    }
  }
  reverse(ALL(s));
  int sum_a = 0;
  int sum_b = 0;
  rep(i, n){
    if(s[i] == '1'){
      sum_b += two_b[i];
      sum_b %= b;
      if(a > 0){
        sum_a += two_a[i];
        sum_a %= a;
      }
    }
  }
  vector<int> ans(n);
  rep(i, n){
    if(s[i] == '1'){
      if(a > 0){
        int tmp_a = sum_a;
        tmp_a -= two_a[i];
        if(tmp_a < 0){
          tmp_a += a;
        }
        tmp_a %= a;
        int num = 1;
        while (tmp_a != 0){
          num++;
          int cn_popcount = 0;
          rep(j, 30){
            if(tmp_a & (1 << j)){
              cn_popcount++;
            }
          }
          tmp_a %= cn_popcount;
        }
        ans[i] = num;
      }else{
        ans[i] = 0;
        continue;
      }
    }else{
      int tmp_b = sum_b;
      tmp_b += two_b[i];
      tmp_b %= b;
      int num = 1;
      while (tmp_b != 0){
          num++;
          int cn_popcount = 0;
          rep(j, 30){
            if(tmp_b & (1 << j)){
              cn_popcount++;
            }
          }
          tmp_b %= cn_popcount;
        }
        ans[i] = num;
    }
  }
  rrep(i, n){
    cout << ans[i] << endl;
  }
}