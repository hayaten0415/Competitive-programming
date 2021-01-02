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

/**
* 10進数 v を base進数の文字列へ変換する。
* @param [in] v    10進数の整数
* @param [in] base 変換した 2~36 のN進数の値
* @return base進数へ変換した文字列
*/
template<typename TypeInt>
std::string Itoa(const TypeInt v, int base)
{
	static const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string ret;
	static numeric_limits<TypeInt> t;
	TypeInt n = v;
	if (t.is_signed) {
		if (v < 0) n *= -1;
	}

	while (n >= base) {
		ret += table[n%base];
		n /= base;
	}
	ret += table[n];
	if (t.is_signed) {
		if (v < 0 && base == 10) ret += '-';
	}
	// 文字列の順番を逆にする
	std::reverse(ret.begin(), ret.end());

	return ret;
}




int main() {
  int n;
  cin >> n;
  string ans = Itoa(n, 36);
  cout << ans << endl;
}