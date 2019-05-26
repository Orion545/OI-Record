#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<vector>
using namespace std;
const int N=1e5+5;
typedef long long ll;
inline int read()
{
	int sum;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	sum=c-'0';
	c=getchar();
	while(c>='0'&&c<='9')
	{
		sum=sum*10+c-'0';
		c=getchar();
	}
	return sum;
}
void write(ll x)
{
	if(x<0)
	{
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct miaow
{
	int f,t,l;
	int bj;
	miaow(int f=0,int t=0,int l=0,int bj=0):f(f),t(t),l(l),bj(bj){}
}imap[N*2];
int str[N]={0},imc=2;
void jb(int f,int t)
{
	imap[imc]=miaow(f,t,str[f],0);
	str[f]=imc++;
	imap[imc]=miaow(t,f,str[t],0);
	str[t]=imc++;
}
int n,m;
string bff;
ll cos[N],fa[N],fac[N];
vector<int> son[N],son2[N];
ll dp[N][2],dp2[N][2];
int strr;
int qd[N]={0};
void dfs(int o,int fa2)
{
	dp[o][0]=0;
	dp[o][1]=cos[o];
	for(int i=str[o];i;i=imap[i].l)
	{
		int t=imap[i].t;
		if(t==fa2)continue;
		fa[t]=o;
		//fac[t]=son[o].size();
		//son[o].push_back(0);
		//son2[o].push_back(0);
		dfs(t,o);
		if(dp[t][0]<dp[t][1])
		{
			dp[o][1]+=dp[t][0];
			//son[o][fac[t]]=0;
		}
		else
		{
			dp[o][1]+=dp[t][1];
			//son[o][fac[t]]=1;
		}
		dp[o][0]+=dp[t][1];
		
		//dp2[o][0]=dp[o][0];
		//dp2[o][1]=dp[o][1];
		//son2[o][fac[t]]=son[o][fac[t]];
	}
}
int qddl[N],qdt=1;
bool dfs2(int o,int fa2)
{
	dp2[o][0]=0;
	dp2[o][1]=cos[o];
	for(int i=str[o];i;i=imap[i].l)
	{
		int t=imap[i].t;
		if(t==fa2)continue;
		if(!dfs2(t,o))return false;
		if(qd[t])
		{
			dp2[o][1]+=dp2[t][qd[t]-1];
			if(qd[t]==1)
			{
				if(qd[o]==1)return false;
				qd[o]=2;
				qddl[qdt++]=o;
			}
		}
		else
		{
			if(dp2[t][0]<dp2[t][1])
			{
				dp2[o][1]+=dp2[t][0];
			}
			else
			{
				dp2[o][1]+=dp2[t][1];
			}
		}
		dp2[o][0]+=dp2[t][1];
	}
	return true;
}

ll solve(int a1,int b1,int a2,int b2)
{
	ll ans;
	qd[a1]=b1;
	qd[a2]=b2;
	qddl[qdt++]=a1;
	qddl[qdt++]=a2;
	if(!dfs2(strr,0))ans=-1;
	else if(qd[strr])
	{
		ans=dp2[strr][qd[strr]-1];
	}
	else
	{
		ans=min(dp2[strr][0],dp2[strr][1]);
	}
	for(int i=1;i<qdt;++i)
	{
		qd[qddl[i]]=0;
	}
	qdt=1;
	return ans;
	/*if(b1)
	{
		if(fa[a1])
		{
			int x=fa[a1];
			if(son2[x][fac[a1]]==0)
			{
				dp2[x][1]=dp2[x][1]-dp2[a1][0]+dp2[a1][1];
				son2[x][fac[a1]]=1;
			}
			while(fa[x])
			{
				int y=fa[x];
				dp2[y][1]-=dp2[x][son2[y][fac[x]]];
				if(dp2[x][0]<dp2[x][1])
				{
					dp2[y][1]+=dp2[x][0];
					son2[y][fac[x]]=0;
				}
				else
				{
					dp2[y][1]+=dp2[x][1];
					son[y][fac[x]]=1;
				}
				x=y;
			}
		}
	}
	else
	{
		if(fa[a1])
		{
			int x=fa[a1];
			if(son2[x][fac[a1]]==1)
			{
				dp2[x][1]=dp2[x][1]-dp2[a1][1]+dp2[a1][0];
				son2[x][fac[a1]]=0;
			}
			x=fa[x];
			if(fa[x])
			{
				int xx=fa[x];
				if(son2[xx][fac[x]]==0)
				{
					dp2[xx][1]=dp2[xx][1]-dp2[x][0]+dp2[x][1];
					son2[xx][fac[x]]=1;
				}
				while(fa[xx])
				{
					int y=fa[xx];
					if(dp2[xx][0]<dp2[xx][1])
					{
						dp2[y][1]+=dp2[xx][0];
						son2[y][fac[xx]]=0;
					}
					else
					{
						dp2[y][1]+=dp2[xx][1];
						son[y][fac[xx]]=1;
					}
					xx=y;
				}
			}
			else
			{
				//qd=1;
				if(qd==0)return -1;
				qd=1;
			}
		}
	}*/
	
}
int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	//srand(time(NULL));
	cin>>n>>m>>bff;
	//cout<<n<<endl;
	for(int i=1;i<=n;i++)
	{
		cos[i]=read();
		//cin>>cos[i];
	}
	//cout<<"!"<<endl;
	for(int i=1;i<n;i++)
	{
		int f=read(),t=read();
		jb(f,t);
	}
	strr=rand()%n+1;
	fa[strr]=0;
	
	dfs(strr,0);
	for(int i=0;i<m;i++)
	{
		int a1=read(),b1=read(),a2=read(),b2=read();
		if(!b1&&!b2)
		{
			if(fa[a1]==a2||fa[a2]==a1)
			{
				write(-1);
				cout<<endl;
				continue;
				//putchar('\n');
			}
		}
		++b1;
		++b2;
		write(solve(a1,b1,a2,b2));
		cout<<endl;
	}
	return 0;
}
