#include<iostream>
#include<cstdio>
using namespace std;
FILE *iin,*outt;
int n,a[100003];
int minn(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	iin=fopen("road.in","rb");
	outt=fopen("road.out","wb");
	fscanf(iin,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		fscanf(iin,"%d",&a[i]);
	}
	int mi=1231232,b=1,e=n,ans=0;
	bool ok=0;
	while(!ok)
	{
		mi=214748363;
		for(int i=b;i<=e+1;i++)
		{
			if(a[i]<=0)
			{
				e=i;break;
			}
			mi=minn(a[i],mi);
		}
		//e--;
		for(int i=b;i<=e-1;i++)
		{
			a[i]-=mi;
		}
		if(!ok)
		{
			while(a[e]<=0&&e<=n)e++;
			if(e>n)
			{
				b=1;e=n;ok=1;
				for(int i=1;i<=n;i++)
				if(a[i]>0){ok=0;b=i;break;}
			}
			else
			{
				b=e;
				e=n;
			}
		}
		ans+=mi;
	}
	fprintf(outt,"%d",ans);
}
