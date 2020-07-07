#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int d;
  cin >> d;
  if(d == 22){
    cout << "Christmas Eve Eve Eve" << endl;
  }else if(d == 23){
    cout << "Christmas Eve Eve" << endl;
  }
  else if (d == 24){
    cout << "Christmas Eve" << endl;
  }
  else{
    cout << "Christmas" << endl;
  }
}