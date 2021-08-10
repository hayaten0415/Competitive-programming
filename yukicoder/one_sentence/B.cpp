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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
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
const auto INF = numeric_limits<T>::max();

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(n== 1){
    cout << -1 << endl;
    return 0;
  }
  bool paindrome = true;
  rep(i, n / 2){
    if(s[i] != s[n-i-1])paindrome = false;
  }
  if(!paindrome){
    cout << n << endl;
  }else{
    string d = string(n, s[0]);
    if(n % 2 == 0){
      if(d == s){
        cout << 0 << endl;
      }else{
        cout << n - 2 << endl;
      }
    }else{
      if(d == s){
        cout << -1 << endl;
      }else{
        if(n == 3){
          cout << -1 << endl;
        }else{
          cout << n - 2 << endl;
        }
      }
    }
  }
}