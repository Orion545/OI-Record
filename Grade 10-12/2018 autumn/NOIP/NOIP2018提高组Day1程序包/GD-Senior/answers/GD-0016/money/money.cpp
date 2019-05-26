#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int read();
int work(int t);
int d[100000];
int main()
{
	freopen("money.in","r",stdin);
	freopen("money.out","w",stdout);
    int T=0;
	T=read();
    for(int i=0;i<T;i++)
    {
    	work(i);
    }
	fclose(stdin);
	fclose(stdout);
	return 0;
}
int read()
{	
	char ch=getchar();
	int x=0,f=1;
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))
	{
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int work(int t)
{
	for(int j=0;j<100000;j++)d[j]=0;
	int n=read();
	int sum=n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		a[i]=read();
	}
	d[0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<100000;j++)
		{
			if(d[j]!=0&&j+a[i]<100000)
			d[j+a[i]]++;
		}
	}
	for(int i=0;i<n;i++)
	{
		if(d[a[i]]>1)sum--;
	}
	cout<<sum<<endl;
	return 0;
}
