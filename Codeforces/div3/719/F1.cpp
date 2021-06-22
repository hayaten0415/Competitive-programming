#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, t, k;
  cin >> n >> t >> k;
  int left = 0, right = n;
  auto ask = [&](int c){
    cout << "? " << 1 << " " << c << endl;
    cout.flush();
    int x;
    cin >> x;
    return x;
  };
  while(right - left > 1){
    int mid = (left + right) / 2;
    int d = ask(mid);
    if(mid - d < k){
      left = mid;
    }else{
      right = mid;
    }
  }
  cout << "! "<< right << endl;
}