#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int a[5005][5000],a2[5005],p[5005],pp[5005],dian=0;
/*struct bi{
	bool operator () (const int &a1,const int &a2){
		if (a2<a1) return true;
		else return false;
	}
};*/
int search(int x)
{
	printf("%d ",x);
	for (int i=1;i<=5000;++i){
		if (p[i]==0&&a[x][i]!=0) {
			p[i]=1;
			search(i);
		}
	}
}
/*int search1(int x)
{
	for (int i=1;i<=5000;++i){
		if (p[i]!=0&&a[x][i]!=0) {
			dian=i;
			return 0;
		}
		if (p[i]==0&&a[x][i]!=0) {
			p[i]=1;
			pp[i]=x;
			search(i);
			if (dian!=0) return 0;
		}
	}
}
int search2(int x){
	printf("%d ",x);
	for (int i=1;i<=5000;++i){
		if (a[x][i]!=0&&i==dian&&){
			bi(dian,x);
		}
		if (p[i]==0&&a[x][i]!=0) {
			p[i]=1;
			search(i);
		}
	}
}*/
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m,Min=0x7fffffff;
	cin>>n>>m;
	for (int i=1;i<=m;++i) {
		int e1,e2;
		scanf ("%d%d",&e1,&e2);
		++a[e1][e2];
		++a[e2][e1];
		Min=min(e1,Min);
		Min=min(e2,Min);
	}
	p[Min]=1;
	//if (n>m)
	search(Min);
	return 0;
}
	/*&if (n==m) {
		search1(Min);
	}*/
/*++a[e1][0];
		a[e1][a[e1][0]]=e2;
		if (a2[e1]==0) a2[e1]=e2;
		else a2[e1]=min(a2[e1],e2);
		++a[e2][0];
		a[e2][a[e2][0]]=e1;
		if (a2[e2]==0) a2[e2]=e1;
		else a2[e2]=min(a2[e2],e1);
		Min=min(e1,Min);
		Min=min(e2,Min);*/
