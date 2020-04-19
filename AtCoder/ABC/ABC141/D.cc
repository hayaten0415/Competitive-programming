#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int n, m;
  int num = 0;
  ll sum = 0;
  cin >> n >> m;
  std::priority_queue<int> q;
  rep(i,n) {
    cin >> num;
    q.push(num);
  }
  rep(i, m){
    num = q.top();
    q.pop();
    num /= 2;
    q.push(num);
  }
  rep(i, n) {
    sum += q.top();
    q.pop();
  }
  cout << sum << endl;
  return 0;
}