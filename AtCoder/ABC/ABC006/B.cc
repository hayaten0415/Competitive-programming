#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //入力を受け取る
    int n;
    cin >> n;
    vector<long long int> FB(n);
    FB[0] = 0;
    FB[1] = 0;
    FB[2] = 1;

    for (int i = 3; i < n; i++)
    {
        FB[i] = (FB[i - 1] + FB[i - 2] + FB[i - 3]) % 10007;
    }
    cout << FB[n - 1] % 10007 << endl;
}