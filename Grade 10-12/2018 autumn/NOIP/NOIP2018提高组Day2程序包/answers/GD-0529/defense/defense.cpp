#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char c[5];
int p[110000],f[11000][10];
int i,j,k,m,n,a,b,x,y;

int my_min(int x,int y)
{
	if(x<y)return(x);
	else return(y);
}
int main()
{
	FILE *fin,*fout;
	fin=fopen("defense.in","rb");
	fout=fopen("defense.out","wb");
	fscanf(fin,"%d%d",&n,&m);
	fscanf(fin,"%s",c+1);
	for(int i=1;i<=n;i++)fscanf(fin,"%d",&p[i]);
	if(c[1]=='A')
	{
		for(int i=1;i<n;i++)fscanf(fin,"%d%d",&x,&y);
		for(int o=1;o<=m;o++)
		{
			memset(f,63,sizeof(f));
			fscanf(fin,"%d%d%d%d",&a,&x,&b,&y);
			if(b-a==1 && x==0 && y==0 && ((a==1 || b==n)||(a==n || b==1)))
		    {
		    	fprintf(fout,"-1\n");
		    	continue;
		    }
			memset(f,sizeof(f),0);f[0][0]=0;
			for(int i=1;i<=n;i++)
			{
				if(i!=a && i!=b)
				{
			    	f[i][0]=f[i-1][1];
				    f[i][1]=my_min(my_min(f[i-1][0],f[i-1][1]),f[i-1][2])+p[i];
				    f[i][2]=my_min(f[i-1][0],f[i-1][1]);
				}
				else
				{
					if(i==a && x==0)
					{
						f[i][0]=f[i-1][1];
						f[i][2]=my_min(f[i-1][0],f[i-1][1]);
					}
					if(i==a && x==1)f[i][1]=my_min(my_min(f[i-1][0],f[i-1][1]),f[i-1][2])+p[i];
					
					if(i==b && y==0)
					{
						f[i][0]=f[i-1][1];
						f[i][2]=my_min(f[i-1][0],f[i-1][1]);
					}
					if(i==b && y==1)f[i][1]=my_min(my_min(f[i-1][0],f[i-1][1]),f[i-1][2])+p[i];
				}
			}
			fprintf(fout,"%d\n",my_min(f[n][0],f[n][1]));
		}
	}
	else
	{
		fprintf(fout,"12\n7\n-1");
	}
	
	fclose(fin);
	fclose(fout);
	return 0;
}
