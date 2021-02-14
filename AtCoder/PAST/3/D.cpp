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
vector<string> zero(3), one(3), two(3), three(3), four(3), five(3), six(3), seven(3), eight(3), nine(3);

vector<string> rev(vector<string> s, int k) {
	int h = s.size();
  int w = 3;
  vector<string> res(w);
  rep(i, w)res[i].resize(h);
  rep(i, h) for (int j = k; j < k + w; j++){
    res[j-k][h - 1 - i] = s[i][j];
  }
  return res;
}


void define() {
  zero[0] = "#####";
  zero[1] = "#...#";
  zero[2] = "#####";
  one[0] = "#..#.";
  one[1] = "#####";
  one[2] = "#....";
  two[0] = "###.#";
  two[1] = "#.#.#";
  two[2] = "#.###";
  three[0] = "#.#.#";
  three[1] = "#.#.#";
  three[2] = "#####";
  four[0] = "..###";
  four[1] = "..#..";
  four[2] = "#####";
  five[0] = "#.###";
  five[1] = "#.#.#";
  five[2] = "###.#";
  six[0] = "#####";
  six[1] = "#.#.#";
  six[2] = "###.#";
  seven[0] = "....#";
  seven[1] = "....#";
  seven[2] = "#####";
  eight[0] = "#####";
  eight[1] = "#.#.#";
  eight[2] = "#####";
  nine[0] = "#.###";
  nine[1] = "#.#.#";
  nine[2] = "#####";
}

int main() {
  int n;
  cin >> n;
  vector<string> grid(5);
  rep(i, 5) cin >> grid[i];
  define();
  for (int i = 1; i < 4 * n; i+= 4){
    vector<string> grid2 = rev(grid, i);
    if(grid2 == zero)cout << 0;
    if(grid2 == one)cout << 1;
    if(grid2 == two)cout << 2;
    if(grid2 == three)cout << 3;
    if(grid2 == four)cout << 4;
    if(grid2 == five)cout << 5;
    if(grid2 == six)cout << 6;
    if(grid2 == seven)cout << 7;
    if(grid2 == eight)cout << 8;
    if(grid2 == nine)cout << 9;
  }
  cout << endl;
}