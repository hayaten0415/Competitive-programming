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
  int I = -1, C = -1, T = -1;
  rep(i, n){
    if(I == -1 && (s[i] == 'I' || s[i] == 'i')){ 
      I = i;
      break;
    }
  }
  if(I == -1){ 
    cout << "NO" << endl;
    return 0;
  }
  for (int i = I+1; i < n; i++) {
    if(C == -1 && (s[i] == 'C' || s[i] == 'c')){ 
      C = i;
      break;
    }
  }
  if(C == -1){ 
    cout << "NO" << endl;
    return 0;
  }

  for (int i = C+1; i < n; i++) {
    if(T == -1 && (s[i] == 'T' || s[i] == 't')){ 
      T = i;
      break;
    }
  }
  if(T == -1){ 
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
}