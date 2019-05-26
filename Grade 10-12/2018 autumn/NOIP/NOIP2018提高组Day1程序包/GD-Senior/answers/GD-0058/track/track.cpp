#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;

struct edge	{
	int ne,val,v;
}e[100010];
int top=0,f[100010],b[100010],h[100010],f1,f2,n,m,ans;
int qhy[100010],top2=0,a[100010],p;
bool Djt,djt;
//priority_queue<int,vector<int>,greater<int> > lyy;

void Rea(int x,int w)	{
	if (f[x]+w>f2) f2=f[x]+w;
	if (f2>f1) swap(f1,f2);
}

void dfs1(int x)	{
	int hp=h[x];
	while (hp!=0)	{
		if (!b[e[hp].v]) 	{
			int v=e[hp].v;
			b[v]=1;
			dfs1(v);
			if (x!=1) f[x]=max(f[x],f[v]+e[hp].val);
			else Rea(v,e[hp].val);
		}
		hp=e[hp].ne;
	}
}

bool cmp(int a,int b)	{
	return a>b;
}

bool devide(int x)	{
	int s=0,total=0;
	for (int i=n-1;i>=1;--i)	{
		total+=a[i];
		if (total>=x) {
			++s;total=0;
		}
	}	
	if (s>=m) return true;
	else return false;
}

int main()	{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	memset(h,0,sizeof(h));
	scanf("%d%d",&n,&m);
	Djt=true;djt=true;
	int right=0;
	for (int i=1;i<=n-1;++i)	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if (u!=1) Djt=false;
		if (u+1!=v) djt=false;
		e[++top].ne=h[u];e[top].v=v;e[top].val=w;h[u]=top;
		e[++top].ne=h[v];e[top].v=u;e[top].val=w;h[v]=top;
		
		qhy[++top2]=w;
		a[u]=w;
		right+=a[u];
	}
	if (m==1)	{
		f1=f2=0;
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		b[1]=1;
		dfs1(1);
		ans=f1+f2;
	}
	else if (djt)	{
		int left=0;
		while (left+1<right)	{
			int mid=(left+right)/2;
			if (devide(mid)) left=mid;
			else right=mid-1;	
		}
		if (devide(right)) ans=right;
		else if (devide(left)) ans=left;
	}
	else {
		sort(1+qhy,n+qhy,cmp);
		f1=f2=0;
		int r=n-1;
		int s=m*2;
		if (m==n-1)	ans=qhy[n-1];
		if (s<=n-1)	{
			int i=2,j=s-1;
			ans=qhy[1]+qhy[s];
			while (i<j)	{
				ans=min(ans,qhy[i]+qhy[j]);
				i++;j--;
			}
			if (i==j) ans=qhy[i];
		}	//前s个	
		else 	{
			int q=(n-1)-m-1;	 
			ans=qhy[r-q]+qhy[r-1-q];
			for (int i=1;i<=q;++i)	{
				ans=min(ans,qhy[i]+qhy[n-i]);
			}
			for (int i=q+1;i<=n-2-q;++i)
				ans=min(ans,qhy[i]);
		}	//合并部分。 
	}
	printf("%d",ans);
	return 0;
}
