#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=5001;
int n,m;
bool ff[maxn][maxn],lian[maxn],hun[maxn];
int now;
void dfs(int x);
void sao(int b,int x)
{
	cout<<x<<" ";
	lian[x]=1;
	int num;
	for(int i=1;i<=n;i++)
	 if(ff[x][i]&&i!=b&&!lian[i])
	 {
	 	if(hun[i])
	 	 num=i;
	 	 else 
	 	 {
	 	 	ff[i][x]=0;
	 	 	dfs(i);
	 	 }
	 }
	
	if(num<now)
	 sao(x,num);
	else
	{
		memset(hun,0,sizeof(hun));
		dfs(now);
	}
	 
}
void dfs(int x)
{
	cout<<x<<" ";
	lian[x]=1;
	if(hun[x])
	{
		int a[2],num=0;
	    for(int i=1;i<=n;i++)
	    if(ff[x][i]&&!lian[i])
	    {
	 	    if(hun[i])
	 	    {
	 	 	   a[num]=i;
	 	 	   num++;
	 	    }
	 	    else 
	 	    {
	 	 	   ff[i][x]=0;
	 	 	   dfs(i);
	 	    }
	    }
	    if(a[0]<a[1])
	    {
	    	now=a[1];
			sao(x,a[0]);
	    }
		else 
		{
			now=a[0];
			sao(x,a[1]);
		}
	}
	for(int i=1;i<=n;i++)
	 if(ff[x][i]&&!lian[i])
	  dfs(i);
}
int begain;
int huan(int b,int x)
{
	if(lian[x])
	{
		begain=x;
		hun[x]=1;
		return b;
	} 
	lian[x]=1;
	for(int i=1;i<=n;i++)
	 if(i!=b&&ff[x][i])
	  if(huan(x,i)==x&&x!=begain)
	  {
	  	hun[x]=1;
	  	return b;
	  }
	  else return -1;
}
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>m;
	//cout<<n<<" "<<m<<endl;
	for(int i=1;i<=m;i++)
	{
		int f,t;
		cin>>f>>t;
		ff[f][t]=1;
		ff[t][f]=1;
	}
	if(m==n-1)
	 dfs(1);
	else 
	{
		huan(0,1);
		/*for(int i=1;i<=n;i++)
		 if(hun[i])
		  cout<<i<<" ";
		cout<<endl<<endl;*/
		memset(lian,0,sizeof(lian));
		dfs(1);
	}
	return 0;
}
