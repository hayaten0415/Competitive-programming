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
const int INF = (1 << 30);
const int MAX = 1000000;

int main() {
  vector<int> square;
  vector<int> square_odd;
  int i = 1;
  int k = 0;
  int odd_k = 0;
  vector<int> dp1(MAX + 1, INF);
  vector<int> dp2(MAX + 1, INF);
  while(1){
    int num = (i * (i + 1) * (i + 2)) / 6;
    if (num > MAX)break;
    if(num % 2 == 1){
      square_odd.push_back(num);
      odd_k++;
    }
    square.push_back(num);
    i++;
    k++;
  }
  vector<int> X;
  int n = 0;
  while (true){
    int tmp;
    cin >> tmp;
    if(tmp == 0)break;
    n++;
    X.emplace_back(tmp);
  }
  dp1[0] = 0;
  dp2[0] = 0;
  rep(i, MAX + 1){
    rep(j, k){
      if(i - square[j] >= 0){
        dp1[i] = min(dp1[i], dp1[i - square[j]] + 1);
      }
    }
  }
  rep(i, MAX + 1){
    rep(j, odd_k){
      if(i - square_odd[j] >= 0){
        dp2[i] = min(dp2[i], dp2[i - square_odd[j]] + 1);
      }
    }
  }
  rep(i, n){
    cout << dp1[X[i]] << " " << dp2[X[i]] <<  endl;
  }
}