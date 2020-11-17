#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  long double A, B, C;
  cin >> A >> B >> C;
  long double left = max((long double)0.0L, (100.0L - B) / A);
  long double right = (100.0L + B) / A;
  long double mid = (left + right) / 2.0L;
  long double f = A * mid + B * sinf64x((long double)(C * mid * M_PI)) - 100.0L;
  while(abs(f) > 0.00000001L){
    if(f>0.0L){
      right = mid;
    }else{
      left = mid;
    }
    mid = (left + right) / 2.0L;
    f = A * mid + B * sinf64x((long double)(C * mid * M_PI)) - 100.0L;
  }
  cout << fixed << setprecision(12) << mid << endl;
}