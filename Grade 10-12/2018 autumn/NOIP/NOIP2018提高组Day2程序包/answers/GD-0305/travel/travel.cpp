#include<bits/stdc++.h>
using namespace std;
bool a[5002][5002];
int s[5002];
int b[5002];
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		a[x][y]=1;
		a[y][x]=1;
	}
	for(int i=1;i<=n;i++)
	{
		s[i]=i;
		b[i]=5002;
}
	for(int i=1;i<=400000;i++)
	{
		random_shuffle(s+2,s+n+1);
		int cmt=1;
		for(int j=1;j<=m;j++)if(a[s[j]][s[j+1]])cmt++;
		if(cmt==m)
		{
			int f=0;
			for(int j=2;j<=n;j++)
			{
				if(b[j]>s[j])
				{
					
					f=1;break;
				}
				if(s[j]>b[j])break;	
			}
			if(f)for(int j=1;j<=n;j++)b[j]=s[j];
        }
	}
	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}	
