#include<bits/stdc++.h>
//#include<algorithm>
using namespace std;
#define F(j,a,b) for(register int j=a;j<=b;++j)
#define Fu(j,a,b) for(register int j=a;j<b;++j)
#define Fd(j,a,b) for(register int j=a;j>=b;--j)
#define LL long long
inline int read()
{
	int x=0,w=0;char ch=0;
	while(!isdigit(ch))w|=(ch=='-'),ch=getchar();
	while(isdigit(ch))x=(x*10)+(ch^48),ch=getchar();
	return w?-x:x;
}

const int N=50010;
const int M=N;
const int INF=6e8;
vector<int>son[N];
vector<int>w[N];
int maxd[N];
int num[N];
vector<int>sta[N];
//int top[N];
int n,m,ans;
//int vis[N];
int lenn;
void dfs(int u,int fa)
{
	int ff=1;
	int si=son[u].size();
	int k=0;
	sta[u].clear();
	Fu(i,0,si)
	{
		int v=son[u][i];
		if(v==fa)continue;
		dfs(v,u);
		num[u]+=num[v];
		sta[u].push_back(maxd[v]+w[u][i]);
//printf("\n\nu=%d\n",u);
	//	printf(" k=%d,maxd[%d]=%d ",k,v,sta[k]);
		++k;	
		ff=0;
	}
	if(ff)return;
	//memset(vis,0,sizeof(vis));
	sort(sta[u].begin(),sta[u].end() );
	k=sta[u].size();
	int j=k-1,i=0;
	int mmm=0;
/*
	Fu(ee,0,k)
	{
		printf("sta[%d]=%d",ee,sta[ee]);
	}

*/


	for(;i<k;++i)
	{
		//if(son[u][i]==fa)continue;
		//printf(" sta[%d]=%d,sta[%d]=%d",i,sta[i],j,sta[j]);
		if(i>=j)break;
		if(sta[u][i]+sta[u][j]>=lenn)num[u]++,j--;
		else mmm=i;
	}
	
	if(i==j)maxd[u]=sta[u][j];
	else maxd[u]=sta[u][mmm];
	//printf(" maxd[%d]=%d\n",u,maxd[u]);
	sta[u].clear();
}





int check(int len)
{
	lenn=len;
	memset(num,0,sizeof(num));
	memset(maxd,0,sizeof(maxd));
	//top=0;
	//printf("\n\nlenn=%d\n",lenn);
	dfs(2,0);
	//printf("len=%d,lenn=%d,num[1]=%d\n",len,lenn,num[1]);
	if(num[2]>=m)return 1;
	return 0;		
}


int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	F(i,2,n)
	{
		int x=read(),y=read(),l=read();
		son[x].push_back(y);
		son[y].push_back(x);
		w[x].push_back(l);
		w[y].push_back(l);
	}
	int l=1,r=INF,mid;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
		//printf("mid=%d,l=%d,r=%d",mid,l,r);
	}
	
	cout<<ans;
	
	return 0;
}
