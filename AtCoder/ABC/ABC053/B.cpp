#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int a = 0;
  int z = s.size() - 1;
  while(a < z){
    if(s[a]== 'A'){
      break;
    }
    a++;
  }
  while(a < z){
    if(s[z]== 'Z'){
      break;
    }
    z--;
  }
  cout << z - a +1 << endl;
}