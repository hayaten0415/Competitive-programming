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
  int n;
  cin >> n;
  string V = "Vacant";
  string M = "Male";
  string F = "Female";
  string start;
  cout << 0 << endl;
  cin >> start;
  string S;
  if( start == V ) return 0;
  int left = 0;
  int right = n;
  while(right - left > 1){
    int mid = (right+left)/2;
    cout << mid << endl;
    cout.flush();
    cin >> S;
    if( S == V ) return 0;
    if( (S== start && mid % 2 == 1) || (S != start && mid % 2 == 0)){
      right = mid;
    }else{
      left = mid;
    }
  }
}