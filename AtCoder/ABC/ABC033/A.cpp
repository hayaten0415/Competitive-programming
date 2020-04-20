#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string n;
  cin >> n;
  if(n[0] == n[1] && n[1] == n[2] && n[2] == n[3]){
    cout << "SAME" << endl;
  }else {
    cout << "DIFFERENT" << endl;
  }
}