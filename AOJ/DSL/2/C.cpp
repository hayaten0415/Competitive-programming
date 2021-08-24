#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#include <utility>
#include <functional>
#include <time.h>
#include <stack>
#include <array>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
struct FullyIndexableDictionary{
	int len, blk;
	vector<unsigned> bit;
	vector<int> sum;
	FullyIndexableDictionary(){}
	FullyIndexableDictionary(int len):len(len), blk((len+31)>>5), bit(blk), sum(blk){}

	void set(int k){
		bit[k>>5]|=1u<<(k&31);
	}
	void build(){
		for(int i=1; i<blk; i++){
			sum[i]=sum[i-1]+__builtin_popcount(bit[i-1]);
		}
	}
	int rank(int k){
		return sum[k>>5]+__builtin_popcount(bit[k>>5]&((1u<<(k&31))-1));
	}
	int rank(bool v, int k){
		return (v ? rank(k) : k-rank(k));
	}
};
template<typename T, int MAXLOG>
struct WaveletMatrix{
	int len;
	FullyIndexableDictionary mat[MAXLOG];
	int zs[MAXLOG];

	WaveletMatrix(vector<T> data){
		len=data.size();
		vector<T> ls(len), rs(len);
		for(int dep=0; dep<MAXLOG; dep++){
			mat[dep]=FullyIndexableDictionary(len+1);
			int p=0, q=0;
			for(int i=0; i<len; i++){
				bool k=(data[i]>>(MAXLOG-(dep+1)))&1;
				if(k){
					rs[q++]=data[i];
					mat[dep].set(i);
				}else{
					ls[p++]=data[i];
				}
			}
			zs[dep]=p;
			mat[dep].build();
			swap(ls, data);
			for(int i=0; i<q; i++) data[i+p]=rs[i];
		}
	}
	int rank(T v, int l, int r){
		for(int dep=0; dep<MAXLOG; dep++){
			bool bit=(v>>(MAXLOG-(dep+1)))&1;
			l=mat[dep].rank(bit, l)+zs[dep]*bit;
			r=mat[dep].rank(bit, r)+zs[dep]*bit;
		}
		return r-l;
	}
	int rank(T v, int k){
		return rank(v, 0, k);
	}
	T rangemin(int l, int r){
		T ret=0;
		for(int dep=0; dep<MAXLOG; dep++){
			int cntr=mat[dep].rank(0, r), cntl=mat[dep].rank(0, l);
			if(cntl==cntr){
				l=l-cntl+zs[dep];
				r=r-cntr+zs[dep];
				ret=((ret<<1)|1);
			}else{
				l=cntl;
				r=cntr;
				ret<<=1;
			}
		}
		return ret;
	}
	T rangemax(int l, int r){
		T ret=0;
		for(int dep=0; dep<MAXLOG; dep++){
			int cntr=mat[dep].rank(r), cntl=mat[dep].rank(l);
			if(cntl==cntr){
				l=l-cntl;
				r=r-cntr;
				ret<<=1;
			}else{
				l=cntl+zs[dep];
				r=cntr+zs[dep];
				ret=((ret<<1)|1);
			}
		}
		return ret;
	}
	T quantile(int l, int r, int k){ // return k-th largest value in [l,r)
		T ret=0;
		for(int dep=0; dep<MAXLOG; dep++){
			int cntr=mat[dep].rank(r), cntl=mat[dep].rank(l);
			if(cntr-cntl>=k){
				l=cntl+zs[dep];
				r=cntr+zs[dep];
				ret=((ret<<1)|1);
			}else{
				l=l-cntl;
				r=r-cntr;
				ret<<=1;
				k-=(cntr-cntl);
			}
		}
		return ret;
	}
	int freq_dfs(int dep, int l, int r, T val, T a, T b){
		if(l==r) return 0;
		if(dep==MAXLOG) return ((a<=val && val<b) ? r-l : 0);
		T mid=(T(1)<<(MAXLOG-dep-1)|val);
		T right=(((T(1)<<(MAXLOG-dep-1))-1)|mid);
		if(right<a || b<=val) return 0;
		if(a<=val && mid<b) return r-l;
		int cntl=mat[dep].rank(l), cntr=mat[dep].rank(r);
		return freq_dfs(dep+1, l-cntl, r-cntr, val, a, b)+freq_dfs(dep+1, cntl+zs[dep], cntr+zs[dep], mid, a, b);
	}
	int rangefreq(int l, int r, T d, T u){
		return freq_dfs(0, l, r, 0, d, u);
	}
	void list_dfs(int dep, int l, int r, T val, T a, T b, vector<pair<T, int>> &vs){
		if(l==r || b<=val) return;
		if(dep==MAXLOG){
			if(a<=val && val<b) vs.push_back({val, r-l});
			return;
		}
		T mid=(T(1)<<(MAXLOG-dep-1)|val);
		T right=(((T(1)<<(MAXLOG-dep-1))-1)|mid);
		if(right<a) return;
		int cntl=mat[dep].rank(l), cntr=mat[dep].rank(r);
		list_dfs(dep+1, l-cntl, r-cntr, val, a, b, vs);
		list_dfs(dep+1, cntl+zs[dep], cntr+zs[dep], mid, a, b, vs);
	}
	vector<pair<T, int>> freqlist(int l, int r, T d, T u){
		vector<pair<T, int>> ret;
		list_dfs(0, l, r, 0, d, u, ret);
		return ret;
	}
};
int main()
{
	int n;
	scanf("%d", &n);
	using Pi=pair<P, int>;
	vector<Pi> vp(n);
	const int MAX=1e9;
	for(int i=0; i<n; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		y+=MAX;
		vp[i]=Pi(P(x, y), i);
	}
	sort(vp.begin(), vp.end());
	vector<ll> v(n);
	for(int i=0; i<n; i++) v[i]=((ll)vp[i].first.second<<19)|vp[i].second;
	WaveletMatrix<ll, 50> wm(v);
	int q;
	scanf("%d", &q);
	for(int i=0; i<q; i++){
		int sx, tx; ll sy, ty;
		scanf("%d %d %lld %lld", &sx, &tx, &sy, &ty);
		sy+=MAX, ty+=MAX;
		sy<<=19, ty<<=19;
		ty|=n;
		int l=lower_bound(vp.begin(), vp.end(), Pi(P(sx, 0), 0))-vp.begin();
		int r=lower_bound(vp.begin(), vp.end(), Pi(P(tx+1, 0), 0))-vp.begin();
		auto ans1=wm.freqlist(l, r, sy, ty);
		vector<int> ans(ans1.size());
		for(int j=0; j<ans1.size(); j++){
			ans[j]=(ans1[j].first&((1<<19)-1));
		}
		sort(ans.begin(), ans.end());
		for(int j=0; j<ans.size(); j++){
			printf("%d\n", ans[j]);
		}
		printf("\n");
	}
	return 0;
}
