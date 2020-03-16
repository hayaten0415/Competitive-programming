#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, l;
  cin >> n >> l;
  int L = l;
  int R = n + l - 1;
  int eat;
  if(R <= 0){
    eat = R;
  }else if(L >= 0){
    eat = L;
  }else {
    eat = 0;
  }
  cout << (R + L) * (R - L + 1) / 2 - eat << endl;
}