#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=50005;
int toit[N*2],next[N*2],head[N],cost[N*2],tot=1;
int n,m,S;
bool k1,k2,vis[N],used[N];
int dis[N],dep[N],fa[N],top[N],du[N],maxn[N],son[N],size[N];
int ans,max0,max01;
int q[N*10],h,t;
int list[N],rest[N];

void add(int x,int y,int w)
{
	toit[++tot]=y;
	next[tot]=head[x];
	head[x]=tot;
	cost[tot]=w;
}

void build1(int now)
{
	int max1=0,max2=0;
	for (int a=head[now];a;a=next[a])
	{
		int v=toit[a];
		if (fa[now]==v) continue;
		fa[v]=now;
		build1(v);
		
		if (dis[v]+cost[a]>max2)
		{
			if (dis[v]+cost[a]>max1)
			{
				max2=max1;max1=dis[v]+cost[a];
			}
			else max2=dis[v]+cost[a];
		}
	}
	dis[now]=max1;
	ans=max(ans,max2+max1);
}

void work1()//m=1
{
	ans=0;
	build1(1);
	cout<<ans;
}

bool cmp(int a,int b)
{
	return a>b;
}

bool check1(int maxdis)
{
	int j=n,i=2,has=0;
	while (i<j)
	{
		while (i<j&&dis[i]+dis[j]<maxdis) i++;
		if (dis[j]<maxdis)i++;
		j--;
		has++;
		if (has>=m) break;
	}
	return (has>=m);
}


void work2()//ai=1
{
	int ans=0,i=1,j=1e9;
	for (int a=head[1];a;a=next[a]) 
	dis[toit[a]]=cost[a];
	sort(dis+2,dis+n+1);
	j=dis[n]*2;
	while (i<=j)
	{
		int mid=i+j>>1;
		if (check1(mid))
		{
			ans=max(ans,mid);i=mid+1;
		}
		else
		{
			j=mid-1;
		}
	}
	cout<<ans;
	
}

bool check2(int maxdis)
{
	int rest=0,i=1,has=0;
	while (i<n)
	{
		if (rest+dis[i]<maxdis)
		{
			rest+=dis[i++];
		}
		else
		{
			rest=0;i++;has++;
		}
	}
	return has>=m;
}

void work3()//bi=ai+1
{
	for (int a=1;a<n;++a)
	{
		for (int b=head[a];b;b=next[b]) if (toit[b]==a+1) dis[a]=cost[b];
	}
	int i=1,j=0;
	for (int a=1;a<n;++a) 
	{
		cout<<dis[a]<<" ";
		j+=dis[a];
	}
	cout<<endl;
	
	while (i<=j)
	{
		int mid=i+j>>1;
		if (check2(mid))
		{
			ans=max(ans,mid);i=mid+1;
		}else j=mid-1;
	}
	
	cout<<ans;
}

void build(int now,int comedis)
{
	int max1=0,max2=0;
	size[now]=1;
	for (int a=head[now];a;a=next[a])
	{
		int v=toit[a];
		if (v!=fa[now])
		{
			fa[v]=now;
			build(v,cost[a]);
			if (dis[v]>dis[now])
			{
				dis[now]=dis[v];
				son[now]=v;
			}
			if (dis[v]>max2)
			{
				if (dis[v]>max1)
				{
					max2=max1;max1=dis[v];
				}else max2=dis[v];
			}
			maxn[now]=max(maxn[now],maxn[v]);
			size[now]+=1;
		}
	}
	maxn[now]=max(maxn[now],max1+max2);
	dis[now]+=comedis;
}

int check(int now,int maxdis,int comedis)
{
	int result=0;
	int list[1000],cnt=1;
	list[1]=comedis;
	for (int a=head[now];a;a=next[a])
	{
		int v=toit[a];
		if (v==fa[now]) continue;
		result+=check(v,maxdis,cost[a]);
		list[++cnt]=rest[v]+cost[a];
	}
	int result1=result;
	
	
	sort(list+2,list+1+cnt);
	int i=2,j=cnt;
	while (i<j)
	{
		while (i<j&&list[i]+list[j]<maxdis) 
		{
			rest[now]=list[i];
			i++;
		}
		if (list[j]<maxdis) i++;
		j--;
		result++;
	}
	
	//cout<<now<<" "<<result<<" "<<i<<" "<<j<<endl;
	
	sort(list+1,list+1+cnt);
	int i1=1,j1=cnt;
	
	while (i1<j1)
	{
		while (i1<j1&&list[i1]+list[j1]<maxdis) i1++;
		if (i1>=j1) break;
		if (list[j1]<maxdis) i1++;
		j1--;
		result1++;
	}
	//cout<<now<<" "<<result1<<" "<<i1<<" "<<j1<<endl;
	
	
	if (result1>result)
	{
		rest[now]=0;
	}
	else if(i<=j)
	{
		rest[now]=list[j];
	}
	
	
	//cout<<now<<" "<<max(result1,result)<<" "<<rest[now]<<" "<<maxdis<<endl;
	//for (int a=1;a<=cnt;++a) cout<<list[a]<<" ";
	//cout<<"\n\n";
	return max(result1,result);
	
}

void work4()
{
	S=1;
	ans=0;
	while (du[S]!=1) S++;
	build(S,0);
	
	//for (int a=1;a<=n;++a) printf("point=%d  dis=%d\n",a,dis[a]);
	int i=1,j=dis[S];
	while (i<=j)
	{
		int mid=i+j>>1;
		memset(rest,0,sizeof(rest));
		//cout<<endl;
		if (check(S,mid,0)>=m)
		{
			ans=max(ans,mid);
			i=mid+1;
		}
		else j=mid-1;
	}
	cout<<ans<<endl;
}



int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	cin>>n>>m;
	k1=k2=true;
	for (int a=1;a<n;++a)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
		du[x]++;du[y]++;
		max01=max(max01,du[x]);
		max01=max(max01,du[y]);
		if (x!=1) k1=false; 
		if (y-x!=1) k2=false;
	}
	if (m==1) work1();
	else if (k1) work2();
	else if (k2) work3();
	else work4();
	
	
	
	fclose(stdin);fclose(stdout);return 0;
}
