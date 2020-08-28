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


void cut(vector<int>  &A, int k){
  reverse(A.begin(), A.begin() + k);
  reverse(A.begin() + k, A.end());
  reverse(ALL(A));
}

void Ruffle_shuffle(vector<int>  &A){
  int n = A.size();
  vector<int> tmp(n);
  int j = 0;
  int k = n / 2;
  rep(i, n){
    if(i % 2 == 0){
      tmp[i] = A[j];
      j++;
    }else{
      tmp[i] = A[k];
      k++;
    }
  }
  swap(A, tmp);
}

int main() {
  int n, m;
  cin >> n >>m;
  vector<int> A(2 * n);
  rep(i, 2 * n){
    A[i] = i + 1;
  }
  rep(i, m){
    int num;
    cin >> num;
    if(num > 0){
      cut(A, num);
    }else{
      Ruffle_shuffle(A);
    }
  }
  rep(i, 2*n){
    cout << A[i] << endl;
  }
}