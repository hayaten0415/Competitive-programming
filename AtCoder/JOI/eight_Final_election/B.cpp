#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int d, n, m;
  cin >> d >> n >> m;
  vector<int> store;
  vector<int> order(m);
  rep(i, n-1) {
    int num;
    cin >> num;
    store.emplace_back(num);
  }
  store.emplace_back(0);
  sort(ALL(store));
  rep(i, m) {
    cin >> order[i];
  }
  ll cost = 0;
  auto search = [&](int i) {
    int index = lower_bound(ALL(store), order[i]) - store.begin();
    int pre_index = index - 1;
    int after_index = index + 1;
    if (index == 0) pre_index = m-1;
    if(index == m-1)after_index = 0;
    int cos = 1000000000;
    cos = min(cos,min(abs(store[index] - order[i]), abs(store[index] + d - order[i])));
    cos = min(cos, min(abs(store[pre_index] - order[i]), abs(store[pre_index] + d - order[i])));
    cos = min(cos, min(abs(store[after_index] - order[i]), abs(store[after_index] + d - order[i])));
    cost += cos;
  };
  rep(i, m) {
    search(i);
  }
  cout << cost << endl;
}