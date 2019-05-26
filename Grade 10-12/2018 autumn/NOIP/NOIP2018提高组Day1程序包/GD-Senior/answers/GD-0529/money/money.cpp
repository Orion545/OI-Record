#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,k,m,n,o,p,js,jl,t,ma;
int a[1100],f[55000]={0};
int main()
{
	FILE *fin,*fout;
	fin=fopen("money.in","rb");
	fout=fopen("money.out","wb");
	fscanf(fin,"%d",&t);
	for(int o=1;o<=t;o++)
	{
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		f[0]=1;
		fscanf(fin,"%d",&n);m=n;
		for(int i=1;i<=n;i++)fscanf(fin,"%d",&a[i]);
		sort(a+1,a+n+1);ma=a[n];
		
		for(int i=1;i<=n;i++)
		{
			if(f[a[i]]==1)
			{
				m--;
				continue;
			}
			
			for(int j=a[i];j<=ma;j++)
			{
				if(f[j-a[i]]==1)
				f[j]=1;
			}
		}
		fprintf(fout,"%d\n",m);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
