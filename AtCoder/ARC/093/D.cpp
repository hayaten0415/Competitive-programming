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

int main() {
  int a, b;
  cin >> a >> b;
  int k = 50;
  vector<string> grid(2 * k);
  rep(i , 2 * k){
    if(i < k){
      grid[i] = string(2 * k, '#');
    }else{
      grid[i] = string(2 * k, '.');
    }
  }
  int cn_b = 0, cn_a = 0;
  for(int i = 2 * k -2; i>= 0; i-= 2){
    if(cn_b >= b-1)break;
    for (int j = 0; j < 2* k; j += 2){
      if(cn_b >= b-1)break;
      grid[i][j] = '#';
      cn_b++;
    }
  }
  for(int i = 0; i < 2* k; i+= 2){
    if(cn_a >= a-1)break;
    for (int j = 0; j < 2* k; j += 2){
      if(cn_a >= a-1)break;
      grid[i][j] = '.';
      cn_a++;
    }
  }
  cout << 2 * k << " " << 2 * k << endl;
  rep(i, 2* k){
    cout << grid[i] << endl;
  }
}