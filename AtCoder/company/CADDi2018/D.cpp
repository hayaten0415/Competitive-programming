#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  rep(i, n){
    int a;
    cin >> a;
    if(a % 2 == 1){
      cout << "first" << endl;
      return 0;
    }
  }
  cout << "second" << endl;
}