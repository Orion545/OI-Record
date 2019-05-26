#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

int T,n,a[110],newa[110];
bool mark[25010];
bool cmp(int x,int y)
{
	return x<y;
}
void mk(int p,int k,int s,int v)
{
	if(k>p)
	return ;
	for(int i=0;v+newa[k]*i<=s;i++)
	{
		mark[v+newa[k]*i]=1;
		mk(p,k+1,s,v+newa[k]*i);
	}
	
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	
	scanf("%d",&T);
	while(T--)
	{
		memset(a,0,sizeof(a));
		memset(newa,0,sizeof(newa));
		memset(mark,0,sizeof(mark));
		
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		sort(a+1,a+n+1,cmp);

		int cnt=0;
		cnt++;
		newa[cnt]=a[1];
		mk(1,1,a[2],0);
		
		for(int i=2;i<=n;i++)
		{
			if(!mark[a[i]])
			{
				cnt++;
				newa[cnt]=a[i];
			}
			
			mk(cnt,1,a[i+1],0);
		}
		
		printf("%d\n",cnt);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
