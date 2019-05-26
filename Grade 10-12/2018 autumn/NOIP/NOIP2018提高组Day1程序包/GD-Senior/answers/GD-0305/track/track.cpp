#include<bits/stdc++.h>
using namespace std;
int a[1002][1002];
int b[5000002];
int c[5000002];
long long ans,sum;
int s[500002],len[500002];
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*w;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("track.in","r",stdin);
	freopen("track.out","w",stdout);
	int n=read(),m=read();
	int tag=1;
	if(m==1)tag=2;
	for(int i=1;i<=n;i++)s[i]=i;
	for(int i=1;i<=n-1;i++)
	{
		int x=read(),y=read();
		len[i]=read();
	    if(n<=1000)a[x][y]=a[y][x]=len[i];
	    
	}
	if((tag==2)&&n<=1000)
	{
		for(int i=1;i<=20000;i++)
		{
			random_shuffle(s+1,s+n+1);
		    for(int j=1;j<=n;j++)
		    {
		    	if(a[s[j]][s[j+1]])sum+=a[s[j]][s[j+1]];
		    	else break;
		    }
		    ans=max(sum,ans);
		    sum=0;
		}
		printf("%d",ans);
		fclose(stdin);fclose(stdout);
		return 0;
	}
	else 
	{
		sort(len+1,len+n+1,cmp);
	 for(int i=1;i<=2*m;i++)b[i]=len[i];
	 long long tmp=1;
	 for(int i=1;i<=2*m-1;i++)
 	 {
		for(int j=i+1;j<=2*m;j++)
		{
			c[tmp]=b[i]+b[j];
			tmp++;
		}
 	 }
	 sort(c+1,c+tmp,cmp);
	}
    printf("%d",c[2*m]);
	fclose(stdin);fclose(stdout);
	return 0;
}
