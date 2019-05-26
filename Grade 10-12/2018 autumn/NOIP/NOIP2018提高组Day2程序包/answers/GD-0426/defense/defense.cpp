#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>

using namespace std;
vector <int> data[100005];
int n,m,aq,a[100005],ff[100005];
int que[1000005],cost[1000005];
int use[1000005],f1[100005];
int x[100005],fi[100005],y[100005],se[100005];
string str;
long long ans;
char z;

int check(int root)
{
	long long sum=0;
	for (int i=0;i<data[root].size();i++) 
	  if (!ff[data[root][i]]) sum+=a[data[root][i]];	  
	if (sum>a[root]) return 1;
	return 0;
}

void bfs(int rot1,int rot2)
{
	int h,t;
	memset(que,0,sizeof(que));
	memset(use,0,sizeof(use));
	memset(ff,0,sizeof(ff));
	h=1;t=2;
	ff[rot1]=1;      ff[rot2]=1;
	que[1]=rot1;     que[2]=rot2;
	use[1]=f1[rot1];  use[2]=f1[rot2];
	while (h<=t)
	{
		int xx=que[h];
		int tt=t;
		for (int i=0;i<data[xx].size();i++)
		  if (!ff[data[xx][i]])
			{
				if (use[h]==1) 
				{
				  if (check(data[xx][i])) 
				  {
				  	t++;
				  	ff[data[xx][i]]=1;
				  	que[t]=data[xx][i];
				  	use[t]=1;
				  	ans+=a[data[xx][i]];
				  }
				  else
				  {
				  	t++;
				  	que[t]=data[xx][i];
				  	use[t]=0;
				  }
				}
				else
				{
					ff[data[xx][i]]=1;
					t++;
					use[t]=1;
					ans+=a[data[xx][i]];
					que[t]=data[xx][i];
				}	
			}
		h++;
	}
}

int main()
{
	freopen("defense.in","r",stdin);
	freopen("defense.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	cin>>str; z=str[0]; aq=str[1]-48;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		data[x].push_back(y);
		data[y].push_back(x);
	}
	
	for (int i=1;i<=m;i++) scanf("%d%d%d%d",&x[i],&fi[i],&y[i],&se[i]);
	for (int i=1;i<=m;i++)
	{
		int f=0;
		if (!fi[i]&&!se[i])
		  for (int j=0;j<data[x[i]].size();j++)
		    if (data[x[i]][j]==y[i]) 
			  {
				f=true;
				printf("-1\n");
				break;
			  } 
		if (f) continue;
		ans=0;
		f1[x[i]]=fi[i]; f1[y[i]]=se[i];
		ans=ans+a[x[i]]*fi[i]+a[y[i]]*se[i];
		bfs(x[i],y[i]);
		printf("%d\n",ans);
	}

	return 0;
}
