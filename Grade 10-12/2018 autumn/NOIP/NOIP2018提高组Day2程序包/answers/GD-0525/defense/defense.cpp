#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<set>
using namespace std;
FILE *iin,*outt;
int n,m,a[2003],b[2003],x,y,x2,y2,z;
int l[2003][2003];
char type[23];
int main()
{
	iin=fopen("defense.in","rb");
	outt=fopen("defense.out","wb");
	fscanf(iin,"%d%d%s",&n,&m,type);
	for(int i=1;i<=n;i++)
		fscanf(iin,"%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		l[x][y]=1;
		l[y][x]=1;
	}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&x,&y,&x2,&y2);
		memset(b,-1,sizeof(b));
		b[x]=y;b[x2]=y2;
		bool ok=1;
		for(int j=1;j<=n;j++)
		{
		for(int k=1;k<=n;k++)
		{
			if(b[j]==0&&b[k]==-1)
			ans+=a[k];
			if(b[j]==0&&b[k]==0)
			{
				ok=0;
			}
			if(!ok)break;
		}
		if(!ok)break;
		}
		if(!ok)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d",ans);
		}
		ans=0;
	}
	return 0;
}
