#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  rep(i, 5){
    int x;
    cin >> x;
    if(x == 0){
      cout << i + 1 << endl;
      return 0;
    }
  }
}