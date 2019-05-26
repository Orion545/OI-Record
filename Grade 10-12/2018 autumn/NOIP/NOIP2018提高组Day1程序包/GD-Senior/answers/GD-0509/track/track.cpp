#include<bits/stdc++.h>
const int mx=50050;
using namespace std;
struct nw
{
	int n,t,v;
}nx[2*mx];
int u[mx],cnt,used[mx],f[mx],n,m,ctl,h[mx];
long long sum;
bool flgp[mx],flgl[mx];
void getp(int lst,int ct)
{
	for(int j=lst;j<=ct;j++)
	{
		
		for(int i=h[used[j]];i;i=nx[i].n)
			if(!flgp[nx[i].t])
			{
				flgl[nx[i].t]=1;
				if(!flgl[nx[i].t])used[++cnt]=nx[i].t;
				f[used[j]]=nx[i].t;
			}
	}
	for(int i=ct+1;i<=cnt;i++)flgp[used[i]]=1;
	if(cnt<n)getp(ct+1,cnt);
}
long long find(int x)
{
	if(u[x]==1)return nx[h[x]].v;
	long long tmp=0,now=0;
	for(int i=h[x];i;i=nx[i].n)
		(nx[i].t!=f[x])?tmp=max(tmp,find(nx[i].t)):now=nx[i].v;
	return tmp+now;
}
void add(int hd,int v,int w)
{
	u[v]++;
	nx[++ctl].n=h[hd];
	h[hd]=ctl;
	nx[ctl].v=w;
	nx[ctl].t=v;
}
int x,y,z;
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	for(int i=1;i<=n;i++)
		if(u[i]==1)
		{
			used[++cnt]=i;

			flgp[i]=1;
		}
	getp(1,cnt);
	sum=find(used[n]);
	printf("%lld",sum);
}
