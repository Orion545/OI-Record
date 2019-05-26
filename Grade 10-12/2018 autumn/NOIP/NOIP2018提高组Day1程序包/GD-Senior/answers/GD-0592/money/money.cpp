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

const int N=25010;
const int M=N;
const int INF=2e9;
int vis[N];
int sta[N],top;
int a[N];

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int T=read();
	while(T--)
	{
		memset(vis,0,sizeof(vis));
		int n;
		n=read();
		F(i,1,n)a[i]=read();
		sort(a+1,a+1+n);
		int cnt=0;
		F(i,1,n)
		{
			if(vis[a[i]])continue;
			cnt++;
			vis[a[i]]=1;
			F(j,0,25000)
			{
				if(a[i]+j>25000)break;
				if(vis[j])vis[j+a[i]]=1;
			}
		}
		cout<<cnt<<endl;
	}
	
	
	return 0;
}
