//稳住，没到最后一刻绝不放弃
//先关注60'做法，直接树形DP，遍历m次，复杂度为O(nm) 
//其他分数等我写完violence再说 
//这是正解的violence算法
//不是正解的做法不知道。。。 
//我很崩溃！！！！ 

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<cctype>

#include<set>
#include<map>
#include<vector>
#include<numeric>

#define ui unsigned int
#define ic isdigit(c)
#define cg c=getchar()
#define pc putchar
#define et putchar('\n')
#define sp putchar(' ')
#define tt(a) template<typename a>
using namespace std;

tt(GD) void read(GD& x){x=0; bool f=0; char cg;while(!ic) { if(c=='-') f=1; cg; }while(ic) x=(x<<3)+(x<<1)+(c^48),cg;if(f) x=-x;}
tt(GD) void write(GD x){ if(x<0) pc('-'),x=-x; if(x>9) write(x/10);pc(x%10+48);}
tt(GD) GD MIN(GD x,GD y) { return x<y?x:y; }

const int MAXN = 1e5+10,inf=0x3f3f3f3f;
int n,m,w[MAXN];
int a,x,b,y;
int f[MAXN][2];

vector<int> g[MAXN];

void buildtree(){
	read(n); read(m); string a; cin>>a;  //无视之 
	for(int i=1;i<=n;i++) read(w[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		read(u); read(v);
		g[u].push_back(v);
		g[v].push_back(u);
	}	
}

void dfs(int now,int fa)
{
	bool bo=0;
	int d=inf;
	for(ui i=0;i<g[now].size();i++)
	{
		int to=g[now][i];
		if(to==fa) continue;
		
		dfs(to,now);
		
		if(now==a) //spj
			if(x==0)
			{
				//1
				f[now][1]=inf; 
				//0
				if(f[to][1]<=f[to][0]) f[now][0]+=f[to][1],bo=1;
				else
				{
					f[now][0]+=f[to][0];
					d=MIN(d,f[to][1]-f[to][0]);
				}
			}
			else
			{
				//0
				f[now][0]=inf;
				//1
				f[now][1]+=MIN(f[to][1],f[to][0]);
			}
		else if(now==b)
			if(y==0)
			{
				//1
				f[now][1]=inf;
				//0
				if(f[to][1]<=f[to][0]) f[now][0]+=f[to][1],bo=1;
				else
				{
					f[now][0]+=f[to][0];
					d=MIN(d,f[to][1]-f[to][0]);
				}				
			}
			else
			{
				f[now][0]=inf;
				f[now][1]+=MIN(f[to][1],f[to][0]);
			}
		else
		{
			//父节点不驻军 
			if(f[to][1]<=f[to][0]) f[now][0]+=f[to][1],bo=1;
			else
			{
				f[now][0]+=f[to][0];
				d=MIN(d,f[to][1]-f[to][0]);
			}
			//父节点驻军 
			f[now][1]+=MIN(f[to][1],f[to][0]);
		}
		
	}
	f[now][1]+=w[now];
	//如果在父节点选择不驻扎军队而子节点又全部不驻军，那就要找一个子节点补差价 
	if(bo==0)  f[now][0]+=d;
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	buildtree();
	for(int i=1;i<=m;i++)
	{
		read(a); read(x); read(b); read(y);
		dfs(1,0); //以1为root 
		int ans=MIN(f[1][0],f[1][1]);
		write(ans),et;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

