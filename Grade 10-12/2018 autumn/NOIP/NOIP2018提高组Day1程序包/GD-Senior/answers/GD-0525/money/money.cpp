#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
FILE *iin,*outt;
int xuan[103],f[25003],a[103],bj[25003];
int t,n;
int maxx(int a,int b)
{
	return a>b?a:b;
}
int minn(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	iin=fopen("money.in","rb");
	outt=fopen("money.out","wb");
	fscanf(iin,"%d",&t);
	for(int i=1;i<=t;i++)
	{
		fscanf(iin,"%d",&n);
		memset(f,0,sizeof(f));
		memset(bj,0,sizeof(bj));
		int b=2147483,e=0,js=1;
		for(int i=1;i<=n;i++)
		{
			fscanf(iin,"%d",&a[i]);
			bj[a[i]]=233;
			b=minn(b,a[i]);
			e=maxx(e,a[i]);
		}
		xuan[js++]=b;f[b]=1;
		for(int j=b+1;j<=e;j++)
		{
			for(int k=1;k<js;k++)
			{
				f[j]=maxx(f[j],f[j-xuan[k]]);
			}
			if(f[j]==0&&bj[j]==233)
			{
				xuan[js++]=j;
				f[j]=1;
			}
		}
		fprintf(outt,"%d\n",js-1);
	}
}
//I AK IOI
