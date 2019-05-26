#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
long long n,m,f[100001],l,r,k,ge=0;
int head[100001],next[200001],to[200001],quan[200001];
bool is[100001],h[100001];
long long end[100001],top;
bool ans[100001];
//尽量让子节点自己凑的多 选一个最大的往上 
void dfs(int root)
{
	is[root]=1;
	for(int i=head[root];i;i=next[i])
	{
		if(!is[to[i]])
		{
			dfs(to[i]);
			h[to[i]]=1;
		}
	}top=0;
	for(int i=head[root];i;i=next[i])
	{
		if(h[to[i]])
		{
		end[++top]=f[to[i]]+quan[i];	
		}
	}
	sort(end+1,end+top+1);
	if(m==1)
	{
	if(end[top]+end[top-1]>=k)ge++,f[root]=end[top-2];
	else
	f[root]=end[top];return;
	}
	while(end[top]>=k&&top>=1){
	ge++;top--;	
	}
	for(int i=0;i<=top;i++)	ans[i]=0;
    for(int i=1;i<=top;i++)
    {
    	for(int j=i+1;j<=top;j++)
    	if(end[i]+end[j]>=k&&!ans[j]&&!ans[i])
    	{
    		ge++;
    		ans[i]=ans[j]=1;
    	}
    }
	//下一行需重点检查 
    for(int i=top;i>=0;i--)
	{
		if(ans[i]==0)
		{
		f[root]=end[i];break;
		}
	}
	return;
}
bool pan(long long x)
{
	memset(f,0,sizeof(f));ge=0;k=x;
	memset(is,0,sizeof(is));memset(h,0,sizeof(h));
	dfs(1);
	if(ge>=m)return 1;
	return 0;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
       cin>>n>>m;
	   for(int i=1;i<n;i++)
	   {
	   	int x,y,z;
	   	scanf("%d %d %d",&x,&y,&z);
	        next[i]=head[x];head[x]=i;to[i]=y;quan[i]=z;
	        
	        next[i+n]=head[y];head[y]=i+n;to[i+n]=x;quan[i+n]=z;
	        r+=z;
	   }	
	   while(l<r)
	   {
	   	long long mid=(l+r+1)/2;   	
	   	if(pan(mid))
	   	{
	   		l=mid;
	   	}else r=mid-1;
	   }
	   cout<<l<<endl;return 0;
}
