#include <iostream>
#include<string>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    //入力を受け取る
    char w;
    cin >> w;
    switch (w)
    {
        case 'A':
            cout << 'T' << endl;
            break;
        case 'G':
            cout << 'C' << endl;
            break;

        case 'C':
            cout << 'G' << endl;
            break;
        default:
            cout << 'A' << endl;
            break;
        }
}