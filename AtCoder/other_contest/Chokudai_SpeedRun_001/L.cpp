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
  vector<int> ind(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
    ind[A[i]] = i;
  }
  int num = 0;
  rep(i, n){
    if(A[i] == i)continue;
    num++;
    int tmp2 = A[i];
    swap(A[i], A[ind[i]]);
    int tmp = ind[i];
    ind[i] = i;
    ind[tmp2] = tmp;
  }
  if((n - num) % 2 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}