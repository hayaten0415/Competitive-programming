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
const ll INF = (1LL <<60);

string monkey = "monkey";
string pirate = "pirate";
string robot = "robot";
string ninja = "ninja";
string zombie = "zombie";

bool res(string s, string x){
  if(s == monkey){
    if(x == robot || x == ninja){
      return true;
    }else{
      return false;
    }
  }
  if(s == pirate){
    if(x == monkey || x == robot){
      return true;
    }else{
      return false;
    }
  }
  if(s == robot){
    if(x == zombie || x == ninja){
      return true;
    }else{
      return false;
    }
  }
  if(s == ninja){
    if(x == pirate || x == zombie){
      return true;
    }else{
      return false;
    }
  }
  if(s == zombie){
    if(x == monkey || x == pirate){
      return true;
    }else{
      return false;
    }
  }
  return false;
}

int main() {
  string x, y;
  cin >> x >> y;
  if(res(x, y)){
    cout << "Win" << endl;
  }else{
    cout << "Lose" << endl;
  }
}