#include <bits/stdc++.h>
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
constexpr lint MOD = 1000000007;

#define FOR(i, begin, end) for(int i=(int)(begin);i<(int)(end);i++)
#define REP(i, n) FOR(i,0,n)


vector<lint> fac, facInv, inv;
void facInit(int nmax)
{
    fac = facInv = inv = vector<lint>(nmax + 1, 1);
    for (int i = 2; i <= nmax; i++)
    {
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        facInv[i] = facInv[i-1] * inv[i] % MOD;
    }
}

lint nPr(int n, int r)
{
    if (n<r || r<0) return 0;
    return fac[n] * facInv[n-r] % MOD;
}


vector<vector<int> > _partition_dfs(vector<int> &now, int num)
{
    int rem = num - accumulate(now.begin(), now.end(), 0);
    if (!now.empty()) rem = min(rem, now.back());

    vector<vector<int> > ans{now};
    now.push_back(0);
    for (int j=1; j<=rem; j++)
    {
        now.back() = j;
        vector<vector<int> > tmp = _partition_dfs(now, num);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    now.pop_back();
    return ans;
}
// num以下の分割を具体的に列挙する（昇順、各分割内は降順）
vector<vector<int> > partitions(int num)
{
    vector<int> d;
    return _partition_dfs(d, num);
}


int main()
{
    int N;
    cin >> N;
    facInit(N * (N - 1) / 2);

    vector<vector<int>> par_tmp = partitions(N);
    vector<vector<int>> par;
    for (auto v : par_tmp) if (accumulate(v.begin(), v.end(), 0) == N) par.push_back(v);

    vector<vector<lint>> dp(2, vector<lint>(par.size()));
    vector<vector<pint>> trans(par.size());
    vector<int> inner(par.size());

    REP(i, par.size())
    {
        for (auto v : par[i]) inner[i] += v * (v-1) / 2;

        REP(j, par[i].size()) REP(k, j) {
            vector<int> nxt = par[i];
            nxt[k] += par[i][j];
            nxt.erase(nxt.begin() + j);
            sort(nxt.begin(), nxt.end(), greater<int>());
            trans[i].push_back(pint((int)(lower_bound(par.begin(), par.end(), nxt) - par.begin()), par[i][j] * par[i][k]));
        }
    }

    dp[0][0] = 1;

    vector<int> A{0};
    REP(i, N-1)
    {
        int tmp; cin >> tmp;
        A.push_back(tmp);
    }
    A.push_back(N * (N - 1) / 2 + 1);

    FOR(i, 1, A.size())
    {
        REP(j, dp[1].size())
        {
            dp[1][j] = dp[0][j] * nPr(inner[j]-A[i-1], A[i]-A[i-1]-1) % MOD;
            dp[0][j] = 0;
        }
        REP(j, dp[1].size()) for (auto p : trans[j]) (dp[0][p.first] += dp[1][j] * p.second) %= MOD;
    }
    cout << dp[1].back() << endl;
}
