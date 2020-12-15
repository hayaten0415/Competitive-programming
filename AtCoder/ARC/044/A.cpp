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


bool isPrime(int num) {
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) {
      if (num % i == 0) {
        // 素数ではない
        return false;
      }
    }
    // 素数である
    return true;
}

int main() {
  int n;
  cin >> n;
  if(n == 1){
    cout << "Not Prime" << endl;
    return 0;
  }
  if(isPrime(n)){
    cout << "Prime" << endl;
  }else if(n % 2 != 0 && n % 5 != 0 && n % 3 != 0){
    cout << "Prime" << endl;
  }else{
    cout << "Not Prime" << endl;
  }
}