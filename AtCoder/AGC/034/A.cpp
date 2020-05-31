#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, a, b, c, d;
  cin >> n >> a >> b >> c >> d;
  bool ok = false;
  string s;
  cin >> s;
  s = "#" + s + "#";
  for (int i = a; i + 1 <= d; i++){
    if(s[i] == '#' && s[i+1] == '#'){
      cout << "No" << endl;
      return 0;
    }
  }
  if(c > d){
    for (int i = b; i <= d; i++){
      if(s[i-1] == '.' && s[i] == '.' && s[i+1] == '.') ok = true;
    }
    if(!ok){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}