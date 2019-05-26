#include<bits/stdc++.h>
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

const int N=1000010;
int dp[2][N];
const int mo=1e9+7;
int n,m;
vector<int>next[4000];

int check(int i,int j)
{
	//cout<<j;
	j>>=1;
	//cout<<" "<<j<<endl;
	while(j)
	{
		
		int x=(j&1);
		int y=(i&1);
		//printf("x=%d,y=%d;",x,y);
		if(x>y)return 0;
		j>>=1;
		i>>=1;
	}
	return 1;	
}


void init()
{
	int mmm=(1<<n)-1;
	F(i,0,mmm)
	{
		F(j,0,mmm)
		{
			if(check(i,j))next[i].push_back(j);
		}
	}
}


int main()
{
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	cin>>n>>m;
	init();
	int mmm=(1<<n)-1;
/*	
	F(i,0,mmm)
	{
		int si=next[i].size();
		Fu(j,0,si)
		printf("next[%d][%d]=%d\n" ,i,j,next[i][j]);
	}
*/
	int v=0;
	F(i,0,mmm)dp[v][i]=1;
	Fu(i,1,m)
	{
		//F(ll,0,mmm)
		//printf("dp[%d][%d]=%d\n",i,ll,dp[v][ll]);
		//cout<<endl;		
		F(kkk,0,mmm)dp[v^1][kkk]=0;
		F(j,0,mmm)
		{
			int si=next[j].size();
			
			Fu(k,0,si)
			{
				dp[v^1][next[j][k]]+=dp[v][j];
				if(dp[v^1][next[j][k]]>=mo)dp[v^1][next[j][k]]-=mo;
				
			}
		}
		v^=1;
	}
	int ans=0;
	F(i,0,mmm)
	{
		ans+=dp[v][i];
		if(ans>=mo)ans-=mo;
	}
	cout<<ans;
	return 0;
}
