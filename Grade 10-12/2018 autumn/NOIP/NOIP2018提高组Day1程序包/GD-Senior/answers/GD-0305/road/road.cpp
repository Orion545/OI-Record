#include<bits/stdc++.h>
using namespace std;
int d[100002];
int t;
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
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n=read();
	for(int i=1;i<=n;i++)d[i]=read();
	int cmt=1;
	while(!d[cmt])cmt++;
	while(d[cmt])
	{
		for(int i=cmt;i<=n;i++)
		{
			if(!d[i])break;
			d[i]--;
		}
		t++;
		while(!d[cmt])
		{
			if( (cmt==n) && (!d[n]) )break;
			cmt++;
		}
	}
	printf("%d\n",t);
	fclose(stdin);fclose(stdout);
	return 0;
}
