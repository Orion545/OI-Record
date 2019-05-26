#include<iostream>
#include<cstdio>
#include<cstdlib>
#define FOR(A,B,C) for(register int A=B;A<=C;A++)
using namespace std;
void iread(int &cn)
{
    char p='k';cn=0;int k=1;
    while((p<'0')||(p>'9')){if(p=='-')k=-1;p=getchar();}
    while((p>='0')&&(p<='9')){cn=cn*10+p-'0';p=getchar();}
    cn*=k;
}
int n,def[100001],ans;
int qbf[100001];
int main()
{
    ///*
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //*/
    iread(n);
    FOR(i,1,n)iread(def[i]);
    FOR(i,1,n)
    {
    	if(def[i]<=def[i-1])
    	{
    		ans+=(def[i-1]-def[i]);
    		qbf[i]=qbf[i-1];
    	}
    	else
    	{
    		qbf[i]=i-1;
    	}
    }
    /*
    FOR(i,1,n)cout<<def[i]<<" ";cout<<endl;
    FOR(i,1,n)cout<<qbf[i]<<" ";cout<<endl;
    //*/
    int j=n;
    while(j)
    {
    	ans+=def[j]-def[qbf[j]];
    	j=qbf[j];
    }
    printf("%d",ans);
    return 0;
}
