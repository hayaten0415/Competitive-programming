#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //入力を受け取る
    string w;
    int ans = 0;
    cin >> w;

    for(int i = 0; i < w.length(); i++)
    {
        if(w[i] == 'A' && w[i] == 'C' && w[i] == 'G' && w[i] == 'T')
            ans++;
    }

    cout << ans << endl;
}