#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    //入力を受け取る
    int H, W, h, w;
    cin >> H >> W >> h >> w;

    //計算する
    int ans = (H - h) * (W - w);
    cout << ans <<endl;
}