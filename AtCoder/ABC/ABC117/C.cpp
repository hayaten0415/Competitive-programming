#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  int dist = 0;
  vector<int> x(m);
  priority_queue<int> que;
  rep(i, m) cin >> x[i];
  if(n >= m){
    cout << 0 << endl;
    return 0;
  }
  sort(x.begin(), x.end());
  rep(i, m - 1){
    que.push(x[i + 1] - x[i]);
    dist += x[i + 1] - x[i];
  }
  rep(i,n-1){
    int p = que.top(); que.pop();
    dist -= p;
  }
  cout << dist << endl;
}