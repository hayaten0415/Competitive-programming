#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  int JOI = 0;
  int IOI = 0;
  rep(i, n - 2) {
    if(s[i] == 'J' && s[i+1] == 'O' && s[i+2] == 'I'){
      JOI++;
      i += 2;
    }
  }
  rep(i, n - 2) {
    if(s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I'){
      IOI++;
      i++;
    }
  }
  cout << JOI << endl;
  cout << IOI << endl;
}