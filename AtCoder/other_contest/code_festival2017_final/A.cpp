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
  string s;
  cin >> s;
  int n = s.size();
  int k = 16;
  vector<string> ans(k);
  ans[0] = "KIHBR";
  ans[1] = "AKIHBR";
  ans[2] = "KIHABR";
  ans[3] = "KIHBAR";
  ans[4] = "KIHBRA";
  ans[5] = "AKIHABR";
  ans[6] = "AKIHBAR";
  ans[7] = "AKIHBRA";
  ans[8] = "KIHABAR";
  ans[9] = "KIHABRA";
  ans[10] = "KIHBARA";
  ans[11] = "AKIHABAR";
  ans[12] = "AKIHABRA";
  ans[13] = "AKIHBARA";
  ans[14] = "KIHABARA";
  ans[15] = "AKIHABARA";
  rep(i, k){
    if(s == ans[i]){
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}