#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int num = n / 2;
  if(n % 2 == 0){
    cout << num * num << endl;
  }else{
    cout << num * (num + 1) << endl;
  }
}