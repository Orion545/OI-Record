#include<cstdio>
#include<cstring>
#define max(x,y) x=x>y?x:y
using namespace std;
struct node{
	int next,point,value;
}r[100001];int last[50001],top=0;
int f[50001][2];
bool visit[50001];
int d1[50001],d2[50001];
int q[50001][2],head;
int n,m,ans;
void up(int k)
{
	int x=k,h;
	while ((k>>1)&&d1[k]<d1[k>>1])
	{
		h=d1[k];d1[k]=d1[k>>1];d1[k>>1]=h;
		k=k>>1;
	}
	k=x;
	while ((k>>1)&&d2[k]>d2[k>>1])
	{
		h=d2[k];d2[k]=d2[k>>1];d2[k>>1]=h;
		k=k>>1;
	}
	return;
}
void down1(int k,int p)
{
	d1[k]=2100000000;
	while ((k<<1)<=p)
	{
		if ((k<<1)+1>p||d1[k<<1]<d1[(k<<1)+1])
		{
			d1[k]=d1[k<<1];k=k<<1;
		}
		else
		{
			d1[k]=d1[(k<<1)+1];k=(k<<1)+1;
		}
	}
	return;
}
void down2(int k,int p)
{
	d2[k]=-2100000000;
	while ((k<<1)<=p)
	{
		if ((k<<1)+1>p||d2[k<<1]>d2[(k<<1)+1])
		{
			d2[k]=d2[k<<1];k=k<<1;
		}
		else
		{
			d2[k]=d2[(k<<1)+1];k=(k<<1)+1;
		}
	}
	return;
}
void dg(int k)
{
	int l,r1,x,y,gg=0;
	int p=0;
	visit[k]=false;
	for (int i=last[k];i;i=r[i].next)
	if (visit[r[i].point])
	{
		dg(r[i].point);
		if (f[r[i].point][1]+r[i].value>=ans) f[k][0]++;
		else
		{
			p++;head++;
			q[head][0]=f[r[i].point][1]+r[i].value;
			q[head][1]=f[r[i].point][1]+r[i].value;
		}
		f[k][0]+=f[r[i].point][0];
	}
	for (int i=1;i<=p;i++) d1[i]=q[head][0],d2[i]=q[head][1],head--,up(i);
	l=1;r1=p;x=d1[1];y=d2[1];
	while (l<r1)
	{
		while (l<r1&&x+y<ans) max(gg,x),down1(1,p),l++,x=d1[1];
		if (l<r1&&x+y>=ans)
		{
			f[k][0]++;l++;r1--;
			down1(1,p);down2(1,p);
			x=d1[1];y=d2[1];
		}
	}
	if (l<=r1) max(gg,y);
	f[k][1]=gg;
	return;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int x,y,z,left=1,right=500000000,ans1=0;
	scanf("%d%d",&n,&m);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		r[++top].point=y;r[top].next=last[x];r[top].value=z;last[x]=top;
		r[++top].point=x;r[top].next=last[y];r[top].value=z;last[y]=top;
	}
	while (left<=right)
	{
		memset(f,0,sizeof(f));
		memset(visit,1,sizeof(visit));
		ans=(left+right)/2;dg(1);
		if (f[1][0]>=m)
		{
			max(ans1,ans);
			left=ans+1;
		}
		else right=ans-1;
	}
	printf("%d",ans1);
	fclose(stdin);fclose(stdout);
	return 0;
}
