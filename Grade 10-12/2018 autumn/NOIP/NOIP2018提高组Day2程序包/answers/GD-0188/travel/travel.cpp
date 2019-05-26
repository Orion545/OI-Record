#include<bits/stdc++.h>

#define imax(a,b) ((a>b)?(a):(b))
#define imin(a,b) ((a<b)?(a):(b))

using namespace std;

typedef long long ll;

const int N=10003;
int n,m;
int ne[N],to[N],h[N],ko[N],tt;
int kp,ka[5001],kb[5001];
bool vk[5000][5000],ok[5001];
struct data { int h[N]; } ans,ap;

void addedge(int a,int b){
	to[++tt]=b; ne[tt]=h[a]; h[a]=tt; ko[tt]=a;
}

data pmin(data A,data B)
{
	for(int i=1;i<=n;++i)
	{
		if(A.h[i]<B.h[i]) return A; else
		if(A.h[i]>B.h[i]) return B;
	}
	return A;
}

void find(int x,int fa,int fb)
{
	if(!ok[x]) ap.h[++kp]=x,ok[x]=1;
	for(int p=h[x];p;p=ne[p])
	{
		if((ko[p]==fa && to[p]==fb) || (ko[p]==fb && to[p]==fa)) continue;
		int v=to[p];
		if(ok[v]) continue;
		find(v,fa,fb);
	}
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d",&n,&m); tt=0;
	for(int i=1;i<=m;++i)
	{
		int a,b; scanf("%d%d",&a,&b);
		vk[a-1][b-1]=1; vk[b-1][a-1]=1;
		ka[i]=a; kb[i]=b;
	}
	for(int i=1;i<=n;++i)
	for(int j=n;j>=1;--j)
	if(vk[i-1][j-1]) addedge(i,j);
	ans.h[1]=1e9;
	if((n-1)==m)
	{
		ap.h[1]=1e9;
		kp=0; for(int i=1;i<=n;++i) ok[i]=0;
		find(1,0,0);
		if(kp==n) ans=pmin(ans,ap);
	} else
	{
		for(int i=1;i<=m;++i)
		{
			ap.h[1]=1e9;
			kp=0; for(int j=1;j<=n;++j) ok[j]=0;
			find(1,ka[i],kb[i]);
			if(kp==n)
			ans=pmin(ans,ap);
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",ans.h[i]); printf("\n");
	return 0;
}
