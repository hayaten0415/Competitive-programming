#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> place(n);
  vector<bool> used(n, false);
  rep(i, n){
    cin >> A[i];
    A[i]--;
    place[A[i]] = i;
  }
  vector<int> ans;
  bool ok =true;
  rep(i, n){
    if(place[i] == i)continue;
    if(ans.size() >= n)ok = false;
    if(!ok)break;
    int now = place[i];
    while (i < now){
      if(used[now]){
        ok = false;
        break;
      }
      ans.emplace_back(now);
      used[now] = true;
      place[A[now]] = now - 1;
      place[A[now - 1]] = now;
      swap(A[now-1], A[now]);
      now--;
    }
  }
  if(ok){
    if(ans.size() != n-1){
      ok = false;
    }
  }
  if(!ok){
    cout << -1 << endl;
    return 0;
  }
  rep(i, n-1){
    cout << ans[i] << endl;
  }
}