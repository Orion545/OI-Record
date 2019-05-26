#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#define FOR(A,B,C) for(register int A=B;A<=C;++A)
#define TOR(A,B) for(register int A=ehd[B];A;A=e[A].next)
using namespace std;
void iread(int &cn)
{
    int k=1;cn=0;char p='k';
    while((p<'0')||(p>'9')){if(p=='-')k=-1;p=getchar();}
    while((p>='0')&&(p<='9')){cn=cn*10+p-'0';p=getchar();}
    cn*=k;
}
int n,m,ra,rb,cost[100001];string rc;
struct EDGE{int from,to,next;}e[200020];int ehd[100001],cnt;
int f[100001][2],fat[100001];bool isp[100001];
inline void addline(int u,int v){++cnt;e[cnt].next=ehd[u];ehd[u]=cnt;e[cnt].to=v;e[cnt].from=u;}

void dfs(int st,int fa)
{
	fat[st]=fa;
	TOR(u,st)
	{
		if(e[u].to==fa)continue;
		dfs(e[u].to,st);
		f[st][0]+=f[e[u].to][1];
		f[st][1]+=min(f[e[u].to][0],f[e[u].to][1]);
	}
	f[st][1]+=cost[st];
}

int main()
{
    ///*
    freopen("**.in","r",stdin);
    freopen("**.out","w",stdout);
    //*/
    iread(n);iread(m);
    cin>>rc;
    FOR(i,1,n)iread(cost[i]);
    FOR(i,2,n){iread(ra);iread(rb);addline(ra,rb);addline(rb,ra);}
    dfs(1,1);
    //FOR(i,1,n)cout<<i<<":"<<f[i][0]<<","<<f[i][1]<<" ";cout<<endl;
    //system("pause");
    return 0;
}
