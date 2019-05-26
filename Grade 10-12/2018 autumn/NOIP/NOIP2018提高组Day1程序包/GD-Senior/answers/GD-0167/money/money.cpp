#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[500],r[30],b[500];
int QwQ(int i,int j)
{
	return i*j-(i+j);
}
int huzhi(int i,int j)
{
	if(i<2||j<2) return 1;//互质 
	if(i>j)	{
		int tump=i;
		i=j;
		j=tump;
	}//i小数 
	if(j%i==0) return 0;//不互质
	if(j%i!=0) return huzhi(i,j%i); 
}
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
	int t,n,k,maxl,m=0;
	cin>>t;
	int tt=t,qq=1;
	while(tt)
	{
		tt--;
		m=0;maxl=999999;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		if(n!=2&&n!=3)
		{
			for(int i=1;i<n;++i)
		for(int j=1;j<n-i+1;++j)
			if(a[j]>a[j+1])
			{
				int tump=a[j];
				a[j]=a[j+1];
				a[j+1]=tump;
			}//冒泡 
		k=2;
		while(!huzhi(a[1],a[k])&&a[k]!=0)
			k++;
		if(a[k]!=0)
		maxl=QwQ(a[1],a[k]);
		for(int i=1;i<=n;++i)
		{
			m++;
			if(a[i]%a[1]==0&&a[i]<maxl&&i!=1)
				m--;
			if(a[i]>maxl)
			{
				m--;
				break;
			}
		}
		r[qq]=m;
		qq++;
		}
		if(n==2)
		{
			if(huzhi(a[1],a[2]))
			{
				r[qq]=2;
				qq++;
			} 
			else
			{
				r[qq]=1;
				qq++;
			}
		}
		if(n==3)
		{
			int pp;
			for(int i=1;i<n;++i)
		for(int j=1;j<n-i+1;++j)
			if(a[j]>a[j+1])
			{
				int tump=a[j];
				a[j]=a[j+1];
				a[j+1]=tump;
			}//冒泡 
			if(a[3]%a[1]==0&&a[2]%a[1]==0)
			{
				r[qq]=1;
				qq++;
				continue;
			}
			if(a[3]%a[1]==0||a[2]%a[1]==0)
			{
				r[qq]=2;
				qq++;
				continue;
			}
			bool yn=false;
			for(int i=0;a[1]*i<a[3];i++)
			for(int j=0;a[2]*j<a[3];++j)
			{
				if(i*a[1]+j*a[2]==a[3])
				{
					r[qq]=2;
					qq++;
					yn=true;
				}
			}
			if(yn) continue;
			r[qq]=3;	qq++;
		}
	}
	for(int i=1;i<=t;++i)
	printf("%d\n",r[i]);
	fclose(stdin);fclose(stdout);
	return 0;
}
