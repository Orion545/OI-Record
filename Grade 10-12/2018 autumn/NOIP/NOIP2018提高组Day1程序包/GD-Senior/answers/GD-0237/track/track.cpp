#include<cstdio>
#include<cstring>
#include<set>
#include<cctype>
using namespace std;
const int N=50005;
int n,m,tot,ans,cnt,lim;
int pos,mx,all;
bool pd;
int first[N],nex[N<<1],en[N<<1],w[N<<1];
int f[N],fa[N];
multiset<int>t[N];
multiset<int>::iterator it;
inline int read()
{
	int X=0,w=0; char ch=0;
	while(!isdigit(ch)) w|=ch=='-',ch=getchar();
	while(isdigit(ch)) X=(X<<3)+(X<<1)+(ch^48),ch=getchar();
	return w?-X:X;
}
inline void insert(int x,int y,int z)
{
	nex[++tot]=first[x];
	first[x]=tot;
	en[tot]=y;
	w[tot]=z;
}
void find(int x,int y,int z)
{
	if(z>mx) mx=z,pos=x;
	for(int i=first[x];i;i=nex[i])
		if(en[i]^y) find(en[i],x,z+w[i]);
}
void dfs(int x)
{
	for(int i=first[x],to;i;i=nex[i])
		if(en[i]^fa[x])
		{
			dfs(en[i]);
			int num=f[en[i]]+w[i];
			if(num>=lim) cnt++; else t[x].insert(num);
		}
	while(!t[x].empty())
	{
		it=t[x].begin();
		int num=*it;
		t[x].erase(it);
		if(t[x].empty())
		{
			f[x]=num;
			break;
		}
		it=t[x].lower_bound(lim-num);
		if(it==t[x].end())
		{
			f[x]=num;
			continue;
		}
		cnt++;
		t[x].erase(it);
	}
}
void pre(int x)
{
	for(int i=first[x];i;i=nex[i])
		if(en[i]^fa[x])
		{
			fa[en[i]]=x;
			pre(en[i]);
		}
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<n;i++)
	{
		int x=read(),y=read(),z=read();
		all+=z;
		insert(x,y,z);
		insert(y,x,z);
	}
	if(m==1)
	{
		find(1,0,0);
		find(pos,0,0);
		printf("%d",mx);
		return 0;
	}
	pre(1);
	int l=1,r=all/m;
	while(l<=r)
	{
		int mid=l+r>>1;
		memset(f,0,sizeof(f));
		cnt=0,lim=mid;
		dfs(1);
		if(cnt>=m)
		{
			l=mid+1;
			ans=mid;
		}else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
