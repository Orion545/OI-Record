#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int td;
int n;
int a[110];
bool tf[110];
int len,b[110];
int minn=999999999,maxx=0;
bool v[25010];

bool cmp(int x,int y)
{
	return x<y?1:0;
}

int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	scanf("%d",&td);
	for(int z=1;z<=td;z++)
	{
		memset(tf,false,sizeof(tf));
		memset(v,false,sizeof(v));v[0]=true;
		memset(a,0,sizeof(a));
		len=0;minn=999999999;maxx=0;
		int x=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{scanf("%d",&a[i]);maxx=maxx>a[i]?maxx:a[i];}
		sort(a+1,a+n+1,cmp);
		/*for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
		printf("\n");*/
		x++;len++;
		b[len]=a[1];
		for(int i=1;i<=n;i++)
		if(a[i]%a[1]==0)tf[i]=true;
		for(int i=1;i*a[1]<=maxx;i++)
		v[i*a[1]]=true;
		/*for(int i=0;i<=100;i++)
			if(v[i]==true)printf("%d ",i);
			printf("\n");*/
		while(x<n)
		{
//			printf("1x:%d\n",x);
			while(tf[x+1]==true)x++;
			x++;
//			printf("2x:%d\n",x);
			if(x<=n)
			{
				len++;
				b[len]=a[x];
				int tt=(a[x]-1)*(a[1]-1);
//				printf("tt:%d\n",tt);
				minn=minn<tt?minn:tt;
				for(int i=x;i<=n;i++)
					if(a[i]%a[x]==0 || a[i]>=minn)tf[i]=true;
				for(int i=0;i<=minn-a[x];i++)
				if(v[i]==true)v[i+a[x]]=true;
				for(int i=x;i<=n;i++)
				if(v[a[i]]==true)tf[i]=true;
				/*for(int i=0;i<=minn;i++)
				if(v[i]==true)printf("%d ",i);
				printf("\n");*/
				/*for(int i=x;i<=n;i++)
				{
					if(a[i]%a[x]==0 || a[i]>=minn)tf[i]=true;
					else
					{
						for(int k=1;k<len && tf[i]==false;k++)
						{
							for(int j=1;j*a[x]<a[i] && tf[i]==false;j++)
							{
								printf("a[i]:%d a[x]:%d a[k]:%d\n",a[i],a[x],a[k]);
								if((a[i]-j*a[x])%a[k]==0)tf[i]=true;
							}
						}
					}
				}*/
			}
			/*printf("a[x]:%d\n",a[x]);
			for(int i=1;i<=n;i++)
			if(tf[i]==false)printf("%d ",a[i]);
			printf("\n");*/
		}
		printf("%d\n",len);
//		printf("len:%d\n",len);
		/*for(int i=1;i<=len;i++)
		printf("%d ",b[i]);
		printf("\n");*/
//		system("pause");
	}
}
/*
*/
