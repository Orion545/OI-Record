#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
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
int n,m,ra,rb;
struct EDGE{int from,to,next,inc,ord;}e[10020];int ehd[5001],cnt;
bool operator<(EDGE a,EDGE b){return a.to>b.to;}
inline void addline(int u,int v){++cnt;e[cnt].next=ehd[u];ehd[u]=cnt;e[cnt].to=v;e[cnt].from=u;e[cnt].ord=cnt;}
void runa(int st,int fa)
{
	printf("%d ",st);
	priority_queue<EDGE> kr;
	TOR(u,st){if(e[u].to==fa)continue;kr.push(e[u]);}
	while(!kr.empty())
	{
		EDGE g=kr.top();
		kr.pop();
		runa(g.to,st);
	}
}
bool ins[5001];int root;
int runc(int st,int v)
{
	int cflag=0;
	if(ins[st]){root=st;e[v].inc=1;return st;};
	ins[st]=true;
	TOR(u,st){if(e[u].to==e[v].from)continue;if(!cflag)cflag=runc(e[u].to,u);else break;}
	if(cflag)e[v].inc=1;
	ins[st]=false;
	return ((cflag&&cflag!=st)?cflag:0);
}
/*
void showc(int st,int fa)
{
	if(st==root&&fa!=root)return;
	cout<<st<<" ";
	TOR(u,st){if(e[u].to==fa)continue;if(e[u].inc)showc(e[u].to,st);}
}
//*/
int nowmin;
void runb(int st,int tev,int flag)
{
	/*
	cout<<st<<","<<e[tev].from<<":"<<flag<<endl;
	system("pause");
	//*/
	if(flag==2)
	{
		runa(st,e[tev].from);
		return;
	}
	else if(st!=root)
	{
		if(flag==0)
		{
			printf("%d ",st);
			priority_queue<EDGE> kr;
			TOR(u,st){if(e[u].to==e[tev].from)continue;kr.push(e[u]);}
			while(!kr.empty())
			{
				EDGE g=kr.top();
				kr.pop();
				runb(g.to,g.ord,0);
			}
		    return;
		}
		else
		{
			printf("%d ",st);
			priority_queue<EDGE> kr;
			bool kfg=true;
			TOR(u,st){if(e[u].to==e[tev].from)continue;if(e[u].inc){if(e[u].to<nowmin)kr.push(e[u]);}else kr.push(e[u]);}
			while(!kr.empty())
			{
				EDGE g=kr.top();
				kr.pop();
				if(!g.inc)runb(g.to,g.ord,2);
				else runb(g.to,g.ord,1);
			}
		    return;
		}
	}
	else if(st==root)
	{
		if(!flag)
		{
			int tp=0;
			printf("%d ",st);
			priority_queue<EDGE> kr;
			TOR(u,st){if(e[u].to==e[tev].from)continue;if(e[u].inc)tp=(tp?((e[tp].to<e[u].to)?tp:u):u);else kr.push(e[u]);}
			while(!kr.empty())
			{
				EDGE g=kr.top();
				kr.pop();
				runb(g.to,g.ord,2);
			}
			runb(e[tp].to,tp,1);
		    return;
		}
		else
		return;
	}
	return;
}
int main()
{
    ///*
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    //*/
    iread(n);iread(m);
    FOR(i,1,m){iread(ra);iread(rb);addline(ra,rb);addline(rb,ra);}
    if(m==(n-1))
    {
    	runa(1,1);
    }
    else
    {
    	runc(1,0);
    	//showc(root,root);
    	runb(1,0,0);
    }
    return 0;
}
