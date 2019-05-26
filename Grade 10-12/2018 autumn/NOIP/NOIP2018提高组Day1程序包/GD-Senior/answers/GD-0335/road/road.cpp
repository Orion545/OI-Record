#include<cstdio>
#define MAXN 100010

inline int read()
{
	int f=1,x=0;
	char s=getchar();
	while(s<'0'||s>'9'){if(s=='-')f=-1;s=getchar();}
	while(s>='0'&&s<='9'){x=(x<<3)+(x<<1)+s-48;s=getchar();}
	return f*x;
}

int in[MAXN],n,c[MAXN];

int sum(int x)
{
	int ans=0;for(;x;x-=(x&(-x)))ans+=c[x];return ans;
}

void change(int x,int v){for(;x<=n;x+=(x&(-x)))c[x]+=v;}

int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int temp;
	long long ans=0;
	n=read();
	for(int i=1;i<=n;++i)in[i]=read(),change(i,in[i]);
	while(sum(n)!=0)
	{
		for(int i=1;i<=n;++i)
		{
			if(in[i])
			{
				in[i]--;
				if(in[i+1]==0)ans++;
				if(!in[i])temp=sum(i)-sum(i-1),change(i,-temp);
			}
			else continue;
		}	
	}
	printf("%lld",ans);
	return 0;
}
