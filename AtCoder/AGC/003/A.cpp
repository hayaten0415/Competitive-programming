#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string S;
  cin >> S;
  bool n, w, s, e;
  n = false, w = false, s = false, e = false;
  int N = S.size();
  rep(i, N){
    if(S[i] == 'N')n=true;
    if(S[i] == 'W')w=true;
    if(S[i] == 'S')s=true;
    if(S[i] == 'E')e=true;
  }
  int cn = 0;
  if(n)cn++;
  if(w)cn++;
  if(s)cn++;
  if(e)cn++;
  if(cn == 4){
    cout << "Yes" << endl;
    return 0;
  }else if(cn == 3 || cn == 1){
    cout << "No" << endl;
    return 0;
  }else if (cn == 2){
    if(n){
      if(s){
        cout << "Yes" << endl;
        return 0;
      }else{
        cout << "No" << endl;
        return 0;
      }
    }
    if(w){
      if(e){
        cout << "Yes" << endl;
        return 0;
      }else{
        cout << "No" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
    return 0;
  }

}