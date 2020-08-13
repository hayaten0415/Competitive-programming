#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int odd_number = 0;
  rep(i, n) {
    int num;
    cin >> num;
    if(num % 2 == 1)odd_number++;
  }
  if(odd_number % 2 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}