#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//==========================
int i,n,m,u,v,cnt;
int ans[5006],que[5006],pre[5006];
int bj[5006];
vector <int> map[5006];
//==================
bool yes(int *ans,int *que,int k) {
	int ii;
	for (ii=1;ii<=k;ii++) {
		if (ans[ii]!=que[ii])
			return ans[ii]>que[ii];
	}
	return true;
}
//======================
void sear1(int k,int cur) {
	int ii,len=map[cur].size(),nex;
	bool bji_in;
	if (k==n+1) {
		for (ii=1;ii<=n;ii++)
			ans[ii]=que[ii];
		return;
	}
	for (ii=0;ii<len;ii++) {
		nex=map[cur][ii];
		if (!bj[nex]) {
			que[k]=nex;
			if (yes(ans,que,k)) {
				bj[nex]=1;
				pre[nex]=cur;
				sear1(k+1,nex);
				bj[nex]=0;
			}
		}
	}
	if (pre[cur])
		sear1(k,pre[cur]);
	return;
}
//=========================
void sear2(int cur) {
	int ii,ij,len=map[cur].size(),mi,nex;
	if (len)
	for (ij=0;ij<len;ij++) {
		mi=0x7fffffff;
		for (ii=0;ii<len;ii++) {
			nex=map[cur][ii];
			if (nex<mi&&!bj[nex])
				mi=nex;
		}
		if (mi!=2147483647) {
			bj[mi]=true;
			ans[++cnt]=mi;
			sear2(mi);
		}
	}
	return;
}
//==============================
int main() {
	freopen("travel.in","rb",stdin);
	freopen("travel.out","wb",stdout);
	//==================================
	scanf("%d%d",&n,&m);
	for (i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		map[u].push_back(v);
		map[v].push_back(u);
	}
	map[0].push_back(1);
	//===================
	for (i=1;i<=n;i++)
		ans[i]=0x7fffffff;
	bj[0]=true;
	//====================
	if (m==n)
		sear1(1,0);
	else
		sear2(0);
	//==============
	for (i=1;i<=n;i++)
		printf("%d ",ans[i]);
	//====================
	return 0;
}

