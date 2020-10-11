#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<bool> P(200001, false);
  int num = 0;
  rep(i, n){
    int tmp;
    cin >> tmp;
    P[tmp] = true;
    if(tmp != num){
      cout << num << endl;
    }else{
      for (int k = tmp; k < 200001; k++){
        if(!P[k]){
          num = k;
          cout << num << endl;
          break;
        }
      }
    }
  }
}