#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int N=140010;
long long n,a[N],lg[N];
long long ans=0,len;
struct emm{
	long long val,num;
}m[N][20];

long long read()
{
	char c=getchar();long long x=0,f=1;
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}

void pre()
{
	long long t=1,c=1,k=1;lg[1]=0;
	for(k=1;k<=16;k++)
	{
		t=(t<<1);
		while(c+1<(t<<1))lg[++c]=k;
	}
}

emm cal(long long a,long long b)
{
	len=lg[b-a+1];
	if(m[a][len].val<m[b-(1<<len)+1][len].val)return m[a][len];
	return m[b-(1<<len)+1][len];
}

void gg(long long cur,long long l,long long r,long long adv)
{
	emm t=cal(l,r);
	if(t.val<adv||l>r)return;
	ans=ans+t.val-adv;
	if(l==r)return;
	gg(t.num-1,l,t.num-1,t.val);
	gg(t.num+1,t.num+1,r,t.val);
}

int main()
{
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	pre();
	n=read();
	for(long long i=1;i<=n;i++){m[i][0].val=read();m[i][0].num=i;}
	
	for(long long j=1;j<=lg[n];j++)
	for(long long i=1;i+(1<<(j-1))<=n;i++)
	{
		if(m[i][j-1].val<m[i+(1<<(j-1))][j-1].val){m[i][j].val=m[i][j-1].val;m[i][j].num=m[i][j-1].num;}
		else {m[i][j].val=m[i+(1<<(j-1))][j-1].val;m[i][j].num=m[i+(1<<(j-1))][j-1].num;}
	}
	
	gg(0,1,n,0);
	printf("%lld",ans);
	return 0;
}
