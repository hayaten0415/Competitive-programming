#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 0; 2 * i <= y; i++){
    for (int j = 0; 2 * i + 4 * j <= y; j++){
      if (2 * i + 4 * j == y && i + j == x){
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}