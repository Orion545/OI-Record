#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int a[101],bz[101],n,ans,T,x,y,c,num,tf,f[25001];
int gcd(int a,int b)
{
	if(a%b==0)return b;
	else return gcd(b,a%b);
}
int exgcd(int a,int b)
{
	int x1,y1;
	if(b==0){x=c/a;y=0;return 0;}
	exgcd(b,a%b);
	x1=y;y1=x-y*(a/b);
	x=x1;y=y1;
}
int dg(int z,int v)
{
	int i;
	if(tf==0)return 0;
	if(v==0){tf=0;return 0;}
	if(z==num)return 0;
	if(bz[z]==1)dg(z+1,v);
	else for(i=0;i<=v/a[z];i++)dg(z+1,v-i*a[z]);
}
int main()
{
freopen("money.in","r",stdin);
freopen("money.out","w",stdout);
int i,j,k,g,xj,yj,ma;
scanf("%d",&T);
while(T>=1)
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	ma=0;
	for(i=1;i<=n;i++)
		if(a[i]>ma)ma=a[i];
	sort(a+1,a+n+1);
	memset(bz,0,sizeof(bz));
	memset(f,0,sizeof(f));
	f[0]=1;
	ans=n;
	for(i=1;i<=n;i++)
	{
		tf=1;
		/*for(j=1;j<i&&tf==1;j++)
		{
			if(a[i]%a[j]==0){bz[i]=1;tf=0;ans--;/*printf("%d %d\n",a[i],a[j]);}
			if(bz[j]==0)
				for(k=j+1;k<i&&tf==1;k++)
					if(bz[k]==0)
					{
						//printf("%d %d %d %d %d\n",a[i],gcd(a[j],a[k]),i,a[j],a[k]);
						g=gcd(a[j],a[k]);
						if(a[i]%g==0)
						{
							c=a[i];
							exgcd(a[j],a[k]);
							xj=a[k]/g;yj=a[j]/g;
							//printf("%d %d %d %d %d %d %d\n",a[j],a[k],a[i],x,xj,y,yj);
							if(!(x<0&&y<0))
							{
								if(y<0)y=y+yj*(x/xj),x=x%xj;
								if(x<0)x=x+xj*(y/yj),y=y%yj;
								if(x>0&&y>0){bz[i]=1;tf=0;ans--;/*printf("%d %d %d\n",a[i],a[j],a[k]);}
							}
						}
					}
		}//printf("*%d %d*\n",a[i],tf);*/
		/*num=i;
		dg(1,a[i]);
		if(tf==0){bz[i]=1;ans--;}*/
		if(f[a[i]]==1){bz[i]=1;ans--;}
		else
		{
			for(j=0;j<=ma-a[i];j++)
				if(f[j]==1)f[j+a[i]]=1;
		}
	}
	//if(T==15)for(i=1;i<=n;i++)printf("%d %d\n",a[i],bz[i]);
	printf("%d\n",ans);
	T--;
}
}
