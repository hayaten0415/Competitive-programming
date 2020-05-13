#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

ll N;
void search(ll cur , ll use, ll &counter){
  if(cur > N) return;
  if(use == 0b111) counter++;
  search(cur * 10 + 3, use | 0b001, counter);
  search(cur * 10 + 5, use | 0b010, counter);
  search(cur * 10 + 7, use | 0b100, counter);
}

int main() {
  cin >> N;
  ll ans = 0;
  search(0, 0, ans);
  cout << ans << endl;
}