#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main(){
  string s;
  cin >> s;
  int pointer = 0;
  int del = 0;
  rep(i,s.size()){
    if(s[i] == 'S') pointer++;
    else if(pointer > 0) pointer--, del++;
  }
  cout << s.size() - 2 * del << endl;
}