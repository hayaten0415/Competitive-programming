#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x;
  cin >> x;
  int num = 20;
  if(x < 600){
    num = 8;
  }else if(x < 800){
    num = 7;
  }else if(x < 1000){
    num = 6;
  }else if(x < 1200){
    num = 5;
  }else if(x < 1400){
    num = 4;
  }else if(x < 1600){
    num = 3;
  }else if(x < 1800){
    num = 2;
  }else{
    num = 1;
  }
  cout << num << endl;
}