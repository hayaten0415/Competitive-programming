#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main(){
  int n;
  string s;
  cin >> n >> s;
  string head = "";
  int needleft = 0;
  int pointer = 0;
  rep(i,n){
    if(s[i] == '('){
      pointer++;
    }else {
      if(pointer == 0)needleft++;
      else pointer--;
    }
  }
  int needright = pointer;
  rep(i,needright){
    s += ')';
  }
  rep(i,needleft){
    head += '(';
  }
  head += s;
  cout << head << endl;
}