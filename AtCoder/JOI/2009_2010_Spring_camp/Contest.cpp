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

int fail_count[10][1000];
int open_time[10][1000];
int score[1000];
int ans_score[10];

int main() {
  int N, M, T, X, Y;
  cin >> N >> M >> T >> X >> Y;
  rep(i,M)rep(j,N)open_time[i][j] =-1;
  rep(i, M) cin >> ans_score[i];
  rep(i, Y){
    int t, n, m;
    string s;
    cin >> t >> n >> m >> s;
    n--, m--;
    if(s == "open"){
      if(open_time[m][n]!= -1)continue;
      open_time[m][n] = t;
    }
    if(s == "incorrect"){
      fail_count[m][n]++;
    }
    if(s == "correct"){
      score[n] += max(X, ans_score[m] - (t - open_time[m][n]) - 120 * fail_count[m][n]);
    }
  }
  rep(i,N){
    cout << score[i] << endl;
  }
}