#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using tp = tuple<int, int, int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int a, b, c, n;
  cin >> a >> b >> c >> n;
  vector<int> A(a+b + c, 2);
  vector<tp> res(n);
  rep(i, n){
    int x, y, z, ok;
    cin >> x >> y >> z >> ok;
    x--, y--, z--;
    get<0>(res[i]) = ok;
    get<1>(res[i]) = x;
    get<2>(res[i]) = y;
    get<3>(res[i]) = z;
  }
  sort(ALL(res), greater<tp>());
  rep(i, n){
    if (get<0>(res[i]) == 1){
      A[get<1>(res[i])] = 1;
      A[get<2>(res[i])] = 1;
      A[get<3>(res[i])] = 1;
    }
  }
  rep(i, 3){
    rep(j, n){
      if (A[get<1>(res[j])] == 1 && A[get<2>(res[j])] == 1){
        if (A[get<3>(res[j])] == 2 && get<0>(res[j]) == 0){
          A[get<3>(res[j])] = 0;
        }
      }
      if (A[get<2>(res[j])] == 1 && A[get<3>(res[j])] == 1){
        if (A[get<1>(res[j])] == 2 && get<0>(res[j]) == 0){
          A[get<1>(res[j])] = 0;
        }
      }
      if (A[get<1>(res[j])] == 1 && A[get<3>(res[j])] == 1){
        if (A[get<2>(res[j])] == 2 && get<0>(res[j]) == 0){
          A[get<2>(res[j])] = 0;
        }
      }
    }
  }
  rep(i, a+ b + c){
    cout << A[i] << endl;
  }
}