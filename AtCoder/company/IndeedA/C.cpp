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
  vector<int> score(1000001, 0), people(1000001, 0);
  rep(i, n){
    int s;
    cin >> s;
    score[s]++;
  }
  people[0] = n;
  rep(i,1000000){
    people[i + 1] = people[i] - score[i];
  }
  reverse(ALL(people));
  int q;
  cin >> q;
  rep(i, q){
    int num;
    cin >> num;
    int ans = upper_bound(ALL(people), num) - people.begin();
    if(ans == 1000000 && people[ans] - score[1000000 - ans] <= num){
      ans = ans;
    }else{
      ans--;
    }
    cout << 1000000 - ans << endl;
  }
}