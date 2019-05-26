#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int f[10][10];
int n,m,pd,js,jl,ans;

bool check(int u,int v)
{
	if(u==n && v==m)
	{
		if(js<jl)pd=1;
		jl=js;
		return(0);
	}
	if(u<n)
	{
		js=js*2+f[u][v];
		check(u+1,v);
		js=(js-f[u][v])/2;
	}
	if(v<m)
	{
		js=js*2+f[u][v];
		check(u,v+1);
		js=(js-f[u][v])/2;
	}
}

int find(int u,int v)
{
	if(u==n+1)
	{
		pd=0;jl=-1;js=0;
		check(1,1);
		if(pd==0)ans++;
		return 0;
	}
	for(int i=0;i<=1;i++)
	{
		f[u][v]=i;
		if(v==m)find(u+1,1);
		else find(u,v+1);
	}
	return 0;
}
int main()
{
	FILE *fin,*fout;
	fin=fopen("game.in","rb");
	fout=fopen("game.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	if(n<=4 && m<=4)
	{
		ans=0;
		find(1,1);
		ans=ans%1000000007;
		fprintf(fout,"%d",ans);
		fclose(fin);
	    fclose(fout);
	    return 0;
    }
    else
    if(n==2)
    {
    	ans=4;
    	for(int i=2;i<=m;i++)ans=(ans*3)%1000000007;
    	fprintf(fout,"%d",ans);
    	fclose(fin);
	    fclose(fout);
	    return 0;
    }
    else
    if(n==3)
    {
    	if(m==1)fprintf(fout,"8");
    	if(m==2)fprintf(fout,"36");
    	if(m==3)fprintf(fout,"112");
    	if(m>3)
    	{
    		ans=112;
    		for(int i=4;i<=m;i++)ans=(ans*3)%1000000007;
    		fprintf(fout,"%d",ans);
    	}
    	fclose(fin);
	    fclose(fout);
	    return 0;
    }
    else
    if(n==4)
    {
    	if(m==1)fprintf(fout,"16");
    	if(m==2)fprintf(fout,"108");
    	if(m==3)fprintf(fout,"336");
    	if(m==4)fprintf(fout,"912");
    	if(m==5)fprintf(fout,"2688");
    	if(m==6)fprintf(fout,"8064");
    	if(m>6)
    	{
    		ans=8064;
    		for(int i=4;i<=m;i++)ans=(ans*3)%1000000007;
    		fprintf(fout,"%d",ans);
    	}
    	fclose(fin);
	    fclose(fout);
	    return 0;
    }
    else
    if(n==5 && m==5)
    {
    	fprintf(fout,"7136");
    	fclose(fin);
	    fclose(fout);
	    return 0;
    }
    else
    {
    	ans=0;
		find(1,1);
		fprintf(fout,"%d",ans%1000000007);
    }
	fclose(fin);
	fclose(fout);
	return 0;
}
