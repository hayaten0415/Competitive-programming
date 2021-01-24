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
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> nonten;
  int sum = 0;
  rep(i, n){
    cin >> A[i];
    sum += A[i];
    if(A[i] % 10 != 0)nonten.emplace_back(A[i]);
  }
  if(sum % 10 != 0){
    cout << sum << endl;
    return 0;
  }
  if(nonten.size() == 0 && sum % 10 == 0){
    cout << 0 << endl;
    return 0;
  }
  sort(ALL(nonten));
  cout << sum - nonten[0] << endl;
}