#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct ed{int t,n,w;}e[100010];
int n,m,k,l,w,h[50010],b[3][50010];
bool r1,r2;
bool cmp(ed x,ed y)
{
	return x.w>y.w;
}
void hatE(int x,int f)
{
	for(int i=h[x];i!=0;i=e[i].n)
	{
		if(e[i].t==f) continue;
		hatE(e[i].t,x);
		if(b[0][x]<b[0][e[i].t]+e[i].w)
		{
			if(b[0][x]+b[0][e[i].t]+e[i].w<b[2][e[i].t])
			{
				b[0][x]=b[0][e[i].t]+e[i].w;
				b[1][x]=b[1][e[i].t]+e[i].w;
				b[2][x]=b[2][e[i].t];
			}
			else
			{
				b[1][x]=b[0][x];
				b[0][x]=b[0][e[i].t]+e[i].w;
				b[2][x]=b[0][x]+b[1][x];
			}
		}
		else if(b[1][x]<b[0][e[i].t]+e[i].w)
		{
			b[1][x]=b[0][e[i].t]+e[i].w;
			b[2][x]=b[0][x]+b[1][x];
		}
	}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	r1=r2=1;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&k,&l,&w);
		e[i*2+1].t=l;
		e[i*2+1].n=h[k];
		e[i*2+1].w=w;
		h[k]=i*2+1;
		e[i*2+2].t=k;
		e[i*2+2].n=h[l];
		e[i*2+2].w=w;
		h[l]=i*2+2;
		if(k!=1) r1=0;
		if(k-l!=1) r2=0;
	}
	if(r1)
	{
		sort(e+1,e+n*2-1,cmp);
		if(m>(n-1)/2) printf("%d\n",e[m*2].w);
		else
		{
			l=1e9;
			for(int i=2;i<=m*2;i=i+2) if(l>e[i].w+e[m*4+2-i].w) l=e[i].w+e[m*4+2-i].w;
			printf("%d\n",l);
		} 
	}
	/*else if(r2)
	{
		
	}*/
	else
	{
		hatE(1,0);
		printf("%d\n",b[2][1]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
