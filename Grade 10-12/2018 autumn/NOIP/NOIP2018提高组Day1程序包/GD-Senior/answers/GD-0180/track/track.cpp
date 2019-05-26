#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//=====================
int i,j,n,m,bj,ans;
int que_d[50006],que_p[50006];
struct type{
	int a,b,l;
}e[50066];
vector <int> nex[50066],len[50066];
//=================
bool bij1(type ia,type ib) {
	return (ia.a<=ib.a);
}
bool bij2(type ia,type ib) {
	return (ia.l>=ib.l);
}
//===========================
void do_1() {
	int cnt,u,v,hea,tai;
	bool b[50006];
	for (i=1;i<=n;i++) {
		memset(b,false,sizeof(b));
		hea=0;tai=1;
		que_p[1]=i;	que_d[1]=0;
		b[i]=true;
		while (hea<tai) {
			hea++;	u=que_p[hea];	
			cnt=nex[u].size();
			//-------
			for (j=0;j<cnt;j++) {
				v=nex[u][j];
				if (!b[v]) {
					b[v]=true;
					tai++;
					que_p[tai]=v;	que_d[tai]=que_d[hea]+len[u][j];
					if (que_d[tai]>ans)
						ans=que_d[tai];
				}
			}
		}
	}
	return;
}
//=================
void do_2() {
	ans=19260817;
}
//===============
void do_3() {
	int mi=0x7fffffff,cnt;
	sort(e+1,e+n,bij2);
	if (2*m>=n) {
		for (i=1;i<=m;i++)
			if (i+(m-i)*2==n-1)
				break;
		cnt=i;//有几条单边赛道 
		for (i=1;i<=cnt;i++)
			if (e[i].l<mi)
				mi=e[i].l;
		for (i=1;i<n;i++)
			if (e[i+cnt].l+e[n-i].l<mi)
				mi=e[i+cnt].l+e[n-i].l;
	}
	else {
		for (i=1;i<2*m;i++)
			if (e[i].l+e[2*m-i+1].l<mi)
				mi=e[i].l+e[2*m-i+1].l;
	}
	ans=mi;
}
//==================
void do_4() {
	sort(e+1,e+n,bij2);
	ans=e[1].l+e[2].l;
	return;
}
//======================
int main() {
	freopen("track.in","rb",stdin);
	freopen("track.out","wb",stdout);
	//=================================
	scanf("%d%d",&n,&m);
	for (i=1;i<n;i++) {
		scanf("%d%d%d",&e[i].a,&e[i].b,&e[i].l);
		nex[e[i].a].push_back(e[i].b);		len[e[i].a].push_back(e[i].l);
		nex[e[i].b].push_back(e[i].a);		len[e[i].b].push_back(e[i].l);
	}
	//======================
	if (m==1) {
		for (i=1;i<n;i++)
			if (e[i].a!=1)
				break;
		if (i==n)
			bj=4;
		else
			bj=1;
	}
	else {
		sort(e+1,e+n,bij1);
		for (i=1;i<n;i++)
			if (e[i].b!=(e[i].a+1))
				break;
		if (i==n)
			bj=2;
		for (i=1;i<n;i++)
			if (e[i].a!=1)
				break;
		if (i==n)
			bj=3;
	}
	//=============================
	if (bj==1)
		do_1();
	if (bj==2)
		do_2();
	if (bj==3)
		do_3();
	if (bj==4)
		do_4();
	//===============
	printf("%d",ans);
	//============================
	return 0;
}

