#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdint>
#include <limits>
using namespace std;



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



int main(){
    int n, k;
    cin >> n >> k;
    string s = Itoa(n, k);
    cout << s.length() << endl;
}
