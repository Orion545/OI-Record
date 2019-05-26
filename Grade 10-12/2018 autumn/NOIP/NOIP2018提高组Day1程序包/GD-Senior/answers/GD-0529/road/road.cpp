#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
long long i,j,k,m,n,o,p,ans,js,jl,x,y;
int main()
{
	FILE *fin,*fout;
	fin=fopen("road.in","rb");
	fout=fopen("road.out","wb");
	fscanf(fin,"%lld",&n);
	y=0;ans=0;
	for(int i=1;i<=n;i++)
	{
		fscanf(fin,"%lld",&x);
		if(x-y>0)ans+=x-y;
		y=x;
	}
	fprintf(fout,"%lld",ans);
	fclose(fin);
	fclose(fout);
	return 0;
}
