#include<iostream>
#include<cstdio>
#include<cstdlib>
#define FOR(A,B,C) for(register int A=B;A<=C;++A)
using namespace std;
void iread(int &cn)
{
    int k=1;cn=0;char p='k';
    while((p<'0')||(p>'9')){if(p=='-')k=-1;p=getchar();}
    while((p>='0')&&(p<='9')){cn=cn*10+p-'0';p=getchar();}
    cn*=k;
}
int n,m,rg,rf;bool flag;
struct EDGE{int from,to,next,inc,ord;}e[10000];int ehd[300],cnt;
inline void addline(int u,int v){++cnt;e[cnt].next=ehd[u];ehd[u]=cnt;e[cnt].to=v;e[cnt].from=u;e[cnt].ord=cnt;}
int cnum,dv[10];
void dfs(int num,int ord)
{
	if(ord>=n){cnum=0;for(int i=n-1;i>=0;i--)cnum=cnum*10+dv[i];addline(cnum,num);return;}
	if(num&(1<<ord))
	{
		dv[ord]=1;dfs(num,ord+1);dv[ord]=0;dfs(num,ord+1);
	}
	else
	{
		dv[ord]=0;dfs(num,ord+1);
	}
}
int f[10][1000005];
int main()
{
    ///*
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    //*/
    iread(n);iread(m);
    FOR(i,0,(1<<n)-1)
    {
    	dfs(i,0);
    }
    /*
    FOR(i,0,(1<<n)-1)
    {
    	cout<<i<<":";
    	for(int u=ehd[i];u;u=e[u].next)
    	{
    		cout<<e[u].to<<" ";
    	}
    	cout<<endl;
    }
    //*/
    FOR(i,0,(1<<n)-1)
    {
    	f[i][m]=1;
    }
    for(int u=m;u;u--)
    {
    	FOR(v,0,(1<<n)-1)
    	{
    		int c;
    		for(c=ehd[v];c;c=e[c].next)
    	{
    		f[e[c].to][m-1]+=f[v][m];
    	}
    	f[e[c].to][m-1]%=1000000007;
    	}
    }
    int ans=0;
    FOR(v,0,(1<<n)-1)
    	{
    	ans+=f[v][1];
    	ans%=1000000007;
    	}
    	cout<<ans;
    	return 0;
}
