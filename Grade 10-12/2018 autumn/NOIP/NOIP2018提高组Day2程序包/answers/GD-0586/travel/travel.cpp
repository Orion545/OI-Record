#include<cstring>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<vector>
#include<cstdio>
using namespace std;

namespace mine
{
	typedef long long ll;
	const int INF=0x3f3f3f3f;
	
	const int MAX_N=5100;
	vector<int> hou[MAX_N];
	int y[MAX_N*3];bool v[MAX_N*3];
	int ln=0;void ins(int x,int yy) {y[++ln]=yy;hou[x].push_back(ln);}
	
	int now[MAX_N],ans[MAX_N];
	int n;
	void update()
	{
		for(int i=1;i<=n;i++) if(now[i]!=ans[i])
		{
			if(now[i]<ans[i]) memcpy(ans,now,sizeof now);
			break;
		}
	}
	
	int id;
	bool in[MAX_N];
	void solve(int x,int fa)
	{
		//printf("x=%d fa=%d\n",x,fa);
		in[x]=1;
		
		now[++id]=x;
		for(int t=0;t<(int)hou[x].size();t++)
		{
			int e=hou[x][t];
			int yy=y[e];if(yy==fa or v[e] or in[yy]) continue;
			solve(yy,x);
		}
	}
	
	bool cmp(int e1,int e2) {return y[e1]<y[e2];}
	void main()
	{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);

		int m;scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++)
		{
			int x,y;scanf("%d%d",&x,&y);
			ins(x,y);ins(y,x);
		}
		
		for(int i=1;i<=n;i++) ans[i]=INF;
		for(int i=1;i<=n;i++) sort(hou[i].begin(),hou[i].end(),cmp);
		memset(v,0,sizeof v);
		
		if(m==n-1)
		{
			id=0;
			solve(1,0);
			update();
		}
		else
		{
			for(int t=1;t<=m;t++)
			{
				memset(in,0,sizeof in);
				id=0;
				v[2*t-1]=v[2*t]=1;
				solve(1,0);
				if(id==n) update();//debug
				v[2*t-1]=v[2*t]=0;
			}
		}
		
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	}
}

int main()
{
	srand(time(0));
	mine::main();
}
