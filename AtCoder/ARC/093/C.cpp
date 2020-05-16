#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n+2, 0);
  vector<int> dist(n + 1);
  ll dist_sum = 0;
  for(int i = 1; i < n + 1; i++) cin >> a[i];
  for (int i = 0; i < n + 1; i++){
    dist[i] = abs(a[i + 1] - a[i]);
    dist_sum += dist[i];
  }
  for (int i = 1; i < n + 1; i++){
    ll tmp = dist_sum - dist[i - 1] - dist[i];
    tmp += abs(a[i + 1] - a[i - 1]);
    cout << tmp << endl;
  }
}