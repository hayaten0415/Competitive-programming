#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x, y, z;
  cin >> x >> y >> z;
  if(x % 3 == 0 || y % 3 == 0 || z % 3 == 0){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}