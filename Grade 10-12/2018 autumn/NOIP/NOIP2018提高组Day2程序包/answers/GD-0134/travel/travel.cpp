#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ed{int n,t,id;}e[10010],st[100010];
int n,m,k,l,h[5010],sa[5010],an[5010],t,df[5010],lw[5010],ti;
bool v[5010],r[5010],v2[5010];
bool cmp(ed x,ed y)
{
	return x.t>y.t;
}
void iT(int x,int f)
{
	v[x]=1;
	sa[t]=x;
	df[x]=lw[x]=ti;
	ti++;
	int nt=t;
	t++;
	k=0;
	for(int i=h[x];i!=0;i=e[i].n)
	{
		st[k]=e[i];
		k++;
	}
	sort(st,st+k,cmp);
	l=0;
	for(int i=0;i<k;i++)
	{
		e[st[i].id].n=l;
		l=st[i].id;
	}
	h[x]=l;
	for(int i=h[x];i!=0;i=e[i].n)
	{
		if(v[e[i].t])
		{
			if(e[i].t!=f) lw[x]=df[e[i].t];
			continue;
		}
		iT(e[i].t,x);
		if(lw[x]>lw[e[i].t]) lw[x]=lw[e[i].t];
	}
	if(lw[x]==df[x])
	{
		if(nt+1!=t)
		for(int i=nt;i<t;i++) r[sa[i]]=1;
		t=nt;
	}
	v[x]=0;
}
int se(int x,bool b)
{
	if(!b && sa[t]<x) return 0;
	//printf("%d %d ",x,b);
	v[x]=1;
	if(sa[t]>x) b=1;
	sa[t]=x;
	t++;
	int tt;
	for(int i=h[x];i!=0;i=e[i].n)
	{
		///printf(".%d %d %d.",x,b,e[i].t);
		if(!v[e[i].t])
		{
			tt=se(e[i].t,b);
			if(tt==0)
			{
				v[x]=0;
				return 0;
			}
			if(tt==2) b=1;
		}
	}
	v[x]=0;
	return 1+b;
}
void fi(int x,int f)
{
	v2[x]=1;
	l=0;
	int hh=0,l2=0;
	for(int i=h[x];i!=0;i=e[i].n)
	{
		if(e[i].t==f)
		{
			l=i;
			continue;
		}
		if(r[e[i].t])
		{
			if(l) e[l].n=e[i].n;
			else h[x]=e[i].n;
			for(int j=h[e[i].t];j!=0;j=e[j].n)
			{
				if(e[j].t==x)
				{
					if(l2) e[l2].n=e[j].n;
					else h[e[i].t]=e[j].n;
					t=0;
					//printf("%d:",x);
					se(1,0);
					//printf("\n");
					if(l2) e[l2].n=j;
					else h[e[i].t]=j;
				}
				l2=j;
			}
			if(l) e[l].n=i;
			else h[x]=i;
			hh=e[i].t;
			/*t=0;
			se(1,0);
			printf("\n");*/
			break;
		}
		l=i;
	}
	if(!v2[hh])fi(hh,x);
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&k,&l);
		e[i*2+1].t=l;
		e[i*2+1].n=h[k];
		e[i*2+1].id=i*2+1;
		h[k]=i*2+1;
		e[i*2+2].t=k;
		e[i*2+2].n=h[l];
		h[l]=i*2+2;
		e[i*2+2].id=i*2+2;
	}
	t=0;
	ti=1;
	iT(1,0);
	for(int i=0;i<n;i++) sa[i]=n+1;
	if(n>m) se(1,0);
	else
	{
		for(ti=1;!r[ti];ti++);
		fi(ti,0);
	}
	for(int i=0;i<n;i++) printf("%d ",sa[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
