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

//グリッド90度回転
vector<string> rev(vector<string> s) {
	int h = s.size();
	int w = s[0].size();
	vector<string> res(w);
	rep(i, w)res[i].resize(h);
	rep(i, h)rep(j, w) {
		res[j][h - 1 - i] = s[i][j];
	}
	return res;
}

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> s(h), t(h);
  rep(i, h) cin >> s[i];
  rep(i, h) cin >> t[i];
  rep(d, 4){
    for (int i = -10; i < 10; i++)for(int j = -10; j < 10; j++){
      bool ok = true;
      rep(x, t.size())rep(y, t[0].size()){
        if(t[x][y] == '#'){
          int nx = i + x, ny = j + y;
          if(nx < 0 || ny < 0 || nx >= h || ny >= w)ok = false;
          else{
            if(s[nx][ny] =='#')ok = false;
          }
        }
      }
      if(ok){
        cout << "Yes\n";
        return 0;
      }
    }
    t = rev(t);
  }
  cout << "No\n";
}