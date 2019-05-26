#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//==========================
int i,n,m,ans,num0,num1,cnt,num;
int run[66][66],pic[66][66],runin[66],way[66][66];
//===================
bool dayu(int *ia,int *ib) {
	int ii;
	for (ii=1;ii<=cnt;ii++)
		if (ia[ii]!=ib[ii])
			return ia[ii]>ib[ii];
	return false;
}
bool xydy(int *ia,int *ib) {
	int ii;
	for (ii=0;ii<=cnt;ii++)
		if (ia[ii]!=ib[ii])
			return ia[ii]<ib[ii];
	return true;
}
bool yes() {
	int ii,ij,ik1,ik2,ix,iy;
	for (ii=1;ii<=cnt;ii++) {
		ix=0;iy=0;
		way[ii][0]=pic[0][0];
		for (ij=1;ij<=cnt;ij++) {
			if (run[ii][ij])
				iy++;
			else
				ix++;
			way[ii][ij]=pic[ix][iy];
		}
	}
	for (ii=1;ii<=cnt;ii++) {
		for (ij=1;ij<ii;ij++)
			if (dayu(run[ii],run[ij]))
				if (!xydy(way[ii],way[ij]))
					return false;
	}
	return true;
}
//================
void dfs1(int ik,int num0,int num1) {
	int ii;
	if (ik>n+m-2) {
		cnt++;
		for (ii=1;ii<ik;ii++)
			run[cnt][ii]=runin[ii];
		return;
	}
	if (num0>0) {
		runin[ik]=0;
		dfs1(ik+1,num0-1,num1);
	}
	if (num1>0) {
		runin[ik]=1;
		dfs1(ik+1,num0,num1-1);
	}
	return;
}
//=========
void dfs2(int ix,int iy) {
	if (ix==n) {
		if (yes())
			ans++;
		ans%=1000000007;
		return;
	}
	{
		pic[ix][iy]=0;
		if (iy<m-1)
			dfs2(ix,iy+1);
		else {
			dfs2(ix+1,0);
		}
		//-----------
		pic[ix][iy]=1;
		if (iy<m-1)
			dfs2(ix,iy+1);
		else {
			dfs2(ix+1,0);
		}
	}
}
//==============================
int main() {
	freopen("game.in","rb",stdin);
	freopen("game.out","wb",stdout);
	//================================
	scanf("%d%d",&n,&m);
	//====================
	num0=n-1;	num1=m-1;
	num=n*m;
	dfs1(1,num0,num1);
	//=========================
	dfs2(0,0);
	//===========
	printf("%d",ans);
	//========================
	return 0;
}

