#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int fourth_count = 0;
  int second_count = 0;
  int limit = n / 2;
  rep(i,n){
    ll a;
    cin >> a;
    if(a % 4 == 0) fourth_count++;
    else if(a % 2 == 0)second_count++;
  }
  if(fourth_count + second_count / 2 >= limit){
    cout << "Yes" << endl;
  }else {
    cout << "No" << endl;
  }
}