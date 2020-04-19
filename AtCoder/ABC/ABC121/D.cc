#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

long long calc(long long A)
{

    if (A <= 0)
        return 0;

    //4の時に、0,1,2,3,4までになるので、これは5つの整数まで
    //なので帳尻合わせで１足してあげる。
    A++;
    //10^3 <= 2^10
    //1000 <= 1024
    //10^12 <= 2^40
    //10^12 <= 2進数 40桁くらい

    long long ans = 0;
    //i桁目の偶奇を調べる
    for (int i = 0; i < 50; i++)
    {
        //0桁目 → 周期2
        //1				4
        //2				8
        long long loop = (1LL << (i + 1));
        long long cnt = (A / loop) * (loop / 2);
        //00000.....0011111.....11
        cnt += max(0LL, (A % loop) - (loop / 2));

        //その桁の1の数が奇数だったら足し算
        if (cnt % 2 == 1)
        {
            ans += 1LL << i;
        }
    }

    return ans;
}

int main()
{
    long long A, B;
    cin >> A >> B;
    long long ans = calc(B) ^ calc(A - 1);
    cout << ans << endl;
}
