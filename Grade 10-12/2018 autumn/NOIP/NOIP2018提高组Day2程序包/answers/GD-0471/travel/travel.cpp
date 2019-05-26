#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int r[10020][2],last[5001];
bool bz[5001];
int d[10010],top;
int h[5001];
int n,m;
int rt=0;
bool flag=false;
void qsort(int l,int r)
{
	int i=l,j=r,mid=d[l+rand()%(r-l+1)],h;
	while (i<=j)
	{
		while (d[i]<mid) i++;
		while (d[j]>mid) j--;
		if (i<=j)
		{
			h=d[i];d[i]=d[j];d[j]=h;
			i++;j--;
		}
	}
	if (i<r) qsort(i,r);
	if (l<j) qsort(l,j);
}
void dg1(int k)
{
	bool bz1=false;
	bz[k]=false;printf("%d ",k);
	int l=top+1,ri=top,p;
	for (int i=last[k];i;i=r[i][0])
	if (bz[r[i][1]])
	{
		ri++;top++;d[ri]=r[i][1];
	}
	if (l<=ri) qsort(l,ri);
	while (l<=ri)
	{
		if (!h[d[l]]||d[l]<rt) if (bz[d[l]])  dg1(d[l]);
		l++;
	}
	return;
}
void pdg(int k)
{
	bz[k]=false;printf("%d ",k);
	int x=h[k],y=k;
	while (h[y]!=k) y=h[y];
	int l=top+1,ri=top,p;
	for (int i=last[k];i;i=r[i][0])
	if (bz[r[i][1]])
	{
		ri++;top++;d[ri]=r[i][1];
	}
	if (l<=ri) qsort(l,ri);
	if (x<y) rt=y;
	else rt=x;
	while (l<=ri)
	{
		if (bz[d[l]]) dg1(d[l]);
		if (d[l]==x||d[l]==y) rt=2100000000;
		l++;
	}
}
void dg(int k)
{
	bz[k]=false;printf("%d ",k);
	int l=top+1,ri=top,p,x=0;
	for (int i=last[k];i;i=r[i][0])
	if (bz[r[i][1]])
	{
		ri++;top++;d[ri]=r[i][1];
	}
	if (l<=ri) qsort(l,ri);
	while (l<=ri)
	{
		if (h[d[l]]) pdg(d[l]);
		else if (bz[d[l]]) dg(d[l]);
		l++;
	}
	return;
}
void pd(int k,int ft)
{
	bz[k]=true;
	for (int i=last[k];i;i=r[i][0])
	if (r[i][1]!=ft)
	{
		if (bz[r[i][1]])
		{
			h[r[i][1]]=2100000000;h[k]=r[i][1];
			break;
		}
		pd(r[i][1],k);
		if (h[r[i][1]])
		{
			if (h[k]) {h[k]=r[i][1];flag=true;return;}
			if (!flag) {h[k]=r[i][1];return;}
		}
		if (flag) return;
	}
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		r[i][0]=last[x];r[i][1]=y;last[x]=i;
		r[i+m][0]=last[y];r[i+m][1]=x;last[y]=i+m;
	}
	pd(1,0);
	memset(bz,1,sizeof(bz));
	dg(1);
	fclose(stdin);fclose(stdout);
	return 0;
}
