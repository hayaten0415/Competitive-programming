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
const int two[4] = {6, 2, 4, 8};
const int three[4] = {1, 3, 9, 7};
const int four[2] = {6, 4};
const int seven[4] = {1,7,9,3};
const int eight[4] = {6, 8, 4, 2};
const int nine[2] = {1, 9};


long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  a %= 10;
  if(a == 1 || a== 5 || a== 6 || a== 0){
    cout << a << endl;
    return 0;
  }
  if(a == 2){
    cout << two[modpow(b,c, 4)] << endl;
  }else if(a == 3){
    cout << three[modpow(b, c, 4)] << endl;
  }else if(a == 4){
    cout << four[modpow(b, c, 2)] << endl;
  }else if(a == 7){
    cout << seven[modpow(b, c, 4)] << endl;
  }else if(a == 8){
    cout << eight[modpow(b, c, 4)] << endl;
  }else{
    cout << nine[modpow(b, c, 2)] << endl;
  }
}