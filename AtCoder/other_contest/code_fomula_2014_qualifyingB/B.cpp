#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string n;
  cin >> n;
  int odd_sum = 0;
  int even_sum = 0;
  reverse(n.begin(), n.end());
  for (int i = 0; i < n.size(); i++){
    int a = n[i] - '0';
    if (i % 2 == 0) odd_sum += a;
    else even_sum += a;
  }
  cout << even_sum << " " << odd_sum << endl;
}