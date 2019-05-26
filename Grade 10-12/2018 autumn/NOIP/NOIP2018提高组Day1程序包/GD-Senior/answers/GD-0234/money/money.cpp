#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define FOR(A,B,C) for(register int A=B;A<=C;A++)
using namespace std;
void iread(int &cn)
{
    char p='k';cn=0;int k=1;
    while((p<'0')||(p>'9')){if(p=='-')k=-1;p=getchar();}
    while((p>='0')&&(p<='9')){cn=cn*10+p-'0';p=getchar();}
    cn*=k;
}
int gcd(int x,int y){while(x^=y^=x^=y%=x);return y;}
int T,n,mone[101],nme[101],m,maxmoney;
bool flag,vis[25500];
int main()
{
    ///*
    freopen("money.in","r",stdin);
    freopen("money.out","w",stdout);
    //*/
    iread(T);
    FOR(t,1,T)
    {
    	memset(vis,0,sizeof(vis));
    	memset(mone,0,sizeof(mone));
    	memset(nme,0,sizeof(nme));
    	m=0;
    	vis[0]=1;
    	iread(n);
    	FOR(i,1,n)
    	{
    		iread(mone[i]);
    	}
    	sort(mone+1,mone+n+1);
    	maxmoney=mone[n];
    	FOR(i,1,n)
    	{
    		flag=(!vis[mone[i]]);
    		FOR(j,1,m)
    		{
    			if(!flag)break;
    			if(!(mone[i]%nme[j]))flag=false;
    		}
    		if(flag)
    		{
    			nme[++m]=mone[i];
    			FOR(v,mone[i],maxmoney)if(!vis[v])vis[v]=vis[v-mone[i]];
    		}
    		/*	
    		FOR(k,1,maxmoney)cout<<k<<" ";cout<<endl;
    		FOR(k,1,maxmoney)cout<<vis[k]<<" ";cout<<endl;
    		FOR(k,1,m)cout<<nme[k]<<" ";cout<<endl;
    		//*/
    	}
    	printf("%d\n",m);
    }
}
