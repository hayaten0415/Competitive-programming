#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int k;
  string s;
  cin >> k >> s;
  if(s.length() <= k){
    cout << s << endl;
    return 0;
  }
  rep(i,k){
    cout << s[i];
  }
  cout << "..." << endl;
}